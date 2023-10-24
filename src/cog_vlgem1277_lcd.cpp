#include <Arduino.h>
#include <SPI.h>
#include "cog_vlgem1277_lcd.h"

// ------------------------------------------------------------------------
// private members of class
// ------------------------------------------------------------------------

void COG_VLGEM1277::WrData(uint8_t data) {
  digitalWrite(m_cs,LOW);
  digitalWrite(m_a0,HIGH); // data mode
  SPI.transfer(data);
  digitalWrite(m_cs,HIGH);
}

void COG_VLGEM1277::WrCmd(uint8_t cmd) {
  digitalWrite(m_cs,LOW);
  digitalWrite(m_a0,LOW);  // command mode
  SPI.transfer(cmd);
  digitalWrite(m_cs,HIGH);
}

void COG_VLGEM1277::WrCmd(uint8_t cmd, uint8_t arg) {
  digitalWrite(m_cs,LOW);
  digitalWrite(m_a0,LOW);  // command mode
  SPI.transfer(cmd);
  digitalWrite(m_a0,HIGH); // data mode
  SPI.transfer(arg);
  digitalWrite(m_cs,HIGH);
}

void COG_VLGEM1277::WrCmd(uint8_t cmd, uint8_t arg1, uint8_t arg2) {
  digitalWrite(m_cs,LOW);
  digitalWrite(m_a0,LOW);  // command mode
  SPI.transfer(cmd);
  digitalWrite(m_a0,HIGH); // data mode
  SPI.transfer(arg1);
  SPI.transfer(arg2);
  digitalWrite(m_cs,HIGH);
}

// ------------------------------------------------------------------------
// public members of class
// ------------------------------------------------------------------------

COG_VLGEM1277::COG_VLGEM1277(uint8_t cs,uint8_t mosi,uint8_t clk,uint8_t a0) {
  m_cs       = cs;
  m_mosi     = mosi;
  m_clk      = clk;
  m_a0       = a0;
  m_buf      = (uint8_t*) calloc (LCD_WIDTH*LCD_N_PAGE,sizeof(uint8_t));
  m_buf16    = (uint16_t*) m_buf;
  m_mod      = mod_e::autoRefresh_OFF; // do not automatic refresh on startup
  m_fg_col   = col_e::WHITE; // font colors foreground background
  m_bg_col   = col_e::BLACK;
  m_edge_col = col_e::WHITE; // draw colors border and fill
  m_fill_col = col_e::BLACK;
  m_pat      = pat_e::solid;
  m_lf       = lf_e::autoLF_ON; // wake up with auto linefeed on
};

void COG_VLGEM1277::Begin(void) {
  pinMode(m_cs,   OUTPUT);
  pinMode(m_clk,  OUTPUT);
  pinMode(m_mosi, OUTPUT);
  pinMode(m_a0,   OUTPUT);
  SPI.begin();
  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0)); // 4Mhz, msb-first, mode=(cs=low/rising-edge of sck)
  WrCmd(LCD_CMD_RESET);
  delay(1000);
  WrCmd(LCD_CMD_BUILTIN_OSC_FREQ,0x00);
  WrCmd(LCD_CMD_BUILTIN_OSC|1);
  WrCmd(LCD_CMD_LC_DRIVE_VOLTAGE,0x07);
  WrCmd(LCD_CMD_EL_VOLUME,0x10);
  WrCmd(LCD_CMD_PWR_CONTROL,0b11111);
  WrCmd(LCD_CMD_DUTY_SET,0x11,0x00);
  WrCmd(LCD_CMD_DISPLAY_REVERSE|0);
  WrCmd(LCD_CMD_DISPLAY_ALL_LIGHT|0);
  WrCmd(LCD_CMD_DISPLAY_MODE,0b00);
  WrCmd(LCD_CMD_GRAY_SCALE_PATTERN,0x36);
  WrCmd(LCD_CMD_COM_OUT_STATUS|1);
  WrCmd(LCD_CMD_DISPLAY_START_LINE,0);
  WrCmd(LCD_CMD_DISPLAY_OFFON|1);
}

void COG_VLGEM1277::DrawPixel(int32_t x, int32_t y, col_e color) {
  if((-1<x) && (x<LCD_WIDTH) && (-1<y) && (y<LCD_HEIGHT)) {
    int32_t idx = (x + ((y>>2)*LCD_WIDTH))^1;
    int32_t msk = ((y<<1) & 7);
    switch(color) {
      case col_e::WHITE:{  
        m_buf[idx] |= (1 << msk);
        m_buf[idx] |= (2 << msk);
        break;
      }
      case col_e::LIGHT_GREY:{
        m_buf[idx] &= ~(1 << msk);
        m_buf[idx] |=  (2 << msk);
        break;
      }
      case col_e::GREY:{
        m_buf[idx] |=  (1 << msk);
        m_buf[idx] &= ~(2 << msk);
        break;
      }
      default: { // BLACK
        m_buf[idx] &= ~(1 << msk);
        m_buf[idx] &= ~(2 << msk);
        break;
      }
    }
  }
}

void COG_VLGEM1277::ClearScreen(col_e color) {
  mod_e cur_mode=m_mod;     // save current auto-mode;
  SetRefreshMode(mod_e::autoRefresh_OFF);
  DrawRect(0,0,xMax,yMax,color,color,pat_e::solid);
  RefreshLCD();             // force update
  SetRefreshMode(cur_mode); // restore prev. auto-mode
  SetCursor(0,0);
}

void COG_VLGEM1277::Scroll(void) {
  int32_t ic=0,jc=0,kc=0,lc=0,size_p=LCD_WIDTH;
  int32_t rc=(3+GetFontHeight()) / 4; // round up to 4th steps;
  for (lc=0;lc<rc;lc++) {
    for (jc=0,ic=1;ic<LCD_N_PAGE; ic++,jc++) {
      //printf("scroll x=%d y=%d\n",m_cur_x,m_cur_y);
      uint8_t *src=m_buf+(ic*size_p);
      uint8_t *dst=m_buf+(jc*size_p);
      for (kc=0; kc<size_p; kc++,dst++,src++) {
        *dst=*src;
      }
    }
  } 
  // erase last text-line, i.e. fill with background color
  DrawRect(0,yMax-8,xMax,yMax,m_bg_col,m_bg_col,pat_e::solid);
  RefreshLCD();  // force update
}

void COG_VLGEM1277::RefreshLCD(mod_e mode) {
  if(mod_e::autoRefresh_ON==mode) {  // refresh only if requested
    uint16_t pc=0, ic=0, di=LCD_WIDTH>>1;
    for(pc=0,ic=0; pc<LCD_N_PAGE; pc++,ic+=di) {
      uint8_t pidx=(pc+2)&0x1F;
      WrCmd(LCD_CMD_COL_ADDR,8);     // set column index
      WrCmd(LCD_CMD_PAGE_ADDR,pidx); // set page index 
      WrPage(m_buf16+ic, di);        // transmit page
    }
    //printf("update x=%02d y=%02d \n",m_cur_x,m_cur_y);
  }
}

void COG_VLGEM1277::WrPage(uint16_t* buf16, int32_t len) {
  WrCmd(LCD_CMD_DATA_WRITE);
  while(len) {
    WrData((uint8_t)((*buf16) >> 8));
    WrData((uint8_t)((*buf16)&0xFF));
    buf16++;
    len--;
  }
}

void COG_VLGEM1277::DrawHline(int32_t x0, int32_t x1, int32_t y, col_e color, pat_e pattern) {
  int32_t ic=0;  
  int32_t step= (pat_e::dotted == pattern) ? 2 : 1;
  int32_t len = x1 - x0 + 1;
  for(ic=0;ic<len;ic+=step) {
    DrawPixel(x0+ic,y,color);
  }
  RefreshLCD(m_mod);
  return;
}

void COG_VLGEM1277::DrawVline(int32_t x, int32_t y0, int32_t y1, col_e color, pat_e pattern) {
  int32_t ic=0;
  int32_t step= (pat_e::dotted == pattern) ? 2 : 1;
  int32_t len = y1 - y0 + 1;
  for(ic=0;ic<len;ic+=step) {
    DrawPixel(x,y0+ic,color);
  }
  RefreshLCD(m_mod);
  return;
}

void COG_VLGEM1277::DrawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, col_e color){
  int32_t dx_sym = 0;
  int32_t dy_sym = 0;
  int32_t dx_x2  = 0; 
  int32_t dy_x2  = 0;
  int32_t di     = 0;
  int32_t dx     = x1-x0;
  int32_t dy     = y1-y0;

  if(dx == 0) {   // vertical line 
    AdjustValues(y0,y1);
    DrawVline(x0,y0,y1,color,m_pat);
    return;
  }
  if(dy == 0) {  // horizontal line
    AdjustValues(x0,x1);
    DrawHline(x0,x1,y0,color,m_pat);
    return;
  }
  dx_sym=(dx>0)? 1:-1;
  dy_sym=(dy>0)? 1:-1;
  dx    = dx_sym*dx;
  dy    = dy_sym*dy;
  dx_x2 = dx*2;
  dy_x2 = dy*2;

  if (dx >= dy) {
    di = dy_x2 - dx;
    while (x0 != x1) {
      DrawPixel(x0, y0, color);
      x0 += dx_sym;
      if (di<0) {
        di += dy_x2;
      } else {
        di += dy_x2 - dx_x2;
        y0 += dy_sym;
      }
    }
    DrawPixel(x0, y0, color);
  } else {
    di = dx_x2 - dy;
    while (y0 != y1) {
      DrawPixel(x0, y0, color);
      y0 += dy_sym;
      if (di < 0) {
        di += dx_x2;
      } else {
        di += dx_x2 - dy_x2;
        x0 += dx_sym;
      }
    }
    DrawPixel(x0, y0, color);
  }
  RefreshLCD(m_mod);
  return;
}


void COG_VLGEM1277::DrawBox(int32_t x0, int32_t y0, int32_t x1, int32_t y1, pat_e pat) {
  DrawRect(x0,y0,x1,y1,col_e::WHITE,col_e::NONE,pat);
}

void COG_VLGEM1277::DrawRect(int32_t x0, int32_t y0, int32_t x1, int32_t y1, col_e edge_col, col_e fill_col, pat_e pattern) {
  int32_t xs=(x1>x0) ? x0 : x1;
  int32_t xe=(x1>x0) ? x1 : x0;
  int32_t ys=(y1>y0) ? y0 : y1;
  int32_t ye=(y1>y0) ? y1 : y0;
  int32_t dy=ye-ys;
  if(col_e::NONE != fill_col) {
    for(int32_t ic=0; ic<dy; ic++) {     // draw center with fill-color in solid pattern
      DrawHline(xs,xe,ys+ic,fill_col,pat_e::solid);  
    }
  }
  DrawHline(xs,xe,ys,edge_col,pattern);  // draw border with edge-color and given pattern
  DrawHline(xs,xe,y1,edge_col,pattern);
  DrawVline(xs,ys,ye,edge_col,pattern);
  DrawVline(xe,ys,ye,edge_col,pattern);
  return;
}

void COG_VLGEM1277::DrawCircle(int32_t x0, int32_t y0, int32_t rad, col_e edge_col, col_e fill_col) {
  mod_e cur_mod = GetRefreshMode();       // get current auto-update-mode
  int32_t xc  = -rad;
  int32_t yc  = 0;
  int32_t err = 2-2*rad;
  int32_t e2  = 0;
  SetRefreshMode(mod_e::autoRefresh_OFF); // do not update until cirle is completed
  if(col_e::NONE != fill_col) {           // check if circle should be filled
    do { // draw vertial lines with fill color in solid pattern
      DrawVline(x0-xc, y0-yc, y0+yc, fill_col,pat_e::solid);
      DrawVline(x0+xc, y0-yc, y0+yc, fill_col,pat_e::solid);
      e2 = err;
      if (e2 <= yc) {
        err += ++yc*2+1;
        if (-xc == yc && e2 <= xc) e2 = 0;
      }
      if (e2 > xc) err += ++xc*2+1;
    } while (xc <= 0);
  }
  xc  = -rad;
  yc  = 0;
  err = -2-2*rad;
  e2  = 0;
  do {  // draw border in edge color
    DrawPixel(x0-xc, y0+yc,edge_col);
    DrawPixel(x0+xc, y0+yc,edge_col);
    DrawPixel(x0+xc, y0-yc,edge_col);
    DrawPixel(x0-xc, y0-yc,edge_col);
    e2 = err;
    if (e2 <= yc) {
      err += ++yc*2+1;
      if (-xc == yc && e2 <= xc) { 
        e2 = 0; 
      }
    }
    if (e2 > xc) {
      err += ++xc*2+1;
    }
  } while (xc <= 0);
  SetRefreshMode(cur_mod); // restore auto-update-mode
  RefreshLCD(m_mod);
}

void COG_VLGEM1277::SetFont(uint8_t *font, col_e col_fg, col_e col_bg) {
  m_fnt       = font;            // map ptr to font-table
  m_fnt_hdr   = 7;               // fix header are 7 bytes
  m_fnt_bpc   = m_fnt[0];        // bytes per character
  m_fnt_width = m_fnt[1];        // char outline width 
  m_fnt_height= m_fnt[2];        // char outline height
  m_fnt_bpl   = m_fnt[3];        // bytes per line 
  m_fnt_ch_s  = m_fnt[4];        // start character
  m_fnt_ch_e  = m_fnt[5];        // end character
  m_fnt_prop  = m_fnt[6];        // 0=mono spaced 1=proportional font
  m_fg_col    = col_fg;          // foreground color
  m_bg_col    = col_bg;          // background color
  SetLfMode(lf_e::autoLF_ON);    // wake up with auto linefeed mode
}

void COG_VLGEM1277::DrawChar(uint8_t ch) {
  uint8_t *ch_ptr=nullptr;       // vertical line of characters
  int32_t ic=0;                  // pixel counter
  int32_t xc=0;                  // column counter x-direction
  int32_t yc=0;                  // row counter y-direction
  int32_t bc=0;                  // loops from 0..bytes_per_line of character
  int32_t ch_width=0;            // current character width, important for proportinal fonts
  int32_t ch_idx=ch-m_fnt_ch_s;  // index in char-looup-table

  // is cr-lf character ?
  if ('\n'==ch) { 
    m_cur_x = 0;             // carriage return
    m_cur_y += m_fnt_height; // line feed 
    return;
  } 

  // is valid char ?
  if ((ch < m_fnt_ch_s) || (ch > m_fnt_ch_e)) {
    return;                  // do nothing, char is out of range
  }

  // is bottom of display reached?
  if ((m_cur_y+m_fnt_height) > LCD_HEIGHT) { 
    Scroll();                // scroll up one Text-Line
    m_cur_y -= m_fnt_height; // correct y position of cursor
  } 
  
  // is cursor at the right border and auto-linefeed==ON?
  if ( (lf_e::autoLF_ON==m_lf) && ((m_cur_x+m_fnt_width) > LCD_WIDTH)) {
    m_cur_x = 0;             // carriage return
    m_cur_y += m_fnt_height; // line feed 
  }

  // double check: is bottom reached?
  if ((m_cur_y+m_fnt_height) > LCD_HEIGHT) {
    Scroll();               // scroll up one Text-Line
    m_cur_y -= m_fnt_height;// correct y position of cursor
  }
  
  // cursor-position is OK now, next draw current character 
  ch_ptr = &m_fnt[(ch_idx * m_fnt_bpc) + m_fnt_hdr];  // jump to bitmap of current char
  ch_width = ch_ptr[0];                               // char-width is needed for proportional fonts 
  for(xc=0;xc<m_fnt_width;xc++) {                     // loop in x-direction
    for(yc=0,bc=0;bc<m_fnt_bpl;bc++) {                // if fontheight>8, loop over byte-per-line
      int ln=ch_ptr[1+(xc*m_fnt_bpl)+bc];             // extract line to draw
      for(ic=0;(ic<8)&&(yc<m_fnt_height);ic++,yc++){  // loop in y-direction, stop after all dots are set
        uint8_t msk = (1<<ic);                        // mask single dots
        col_e col=(msk==(ln&msk))?m_fg_col:m_bg_col;  // determine dot: 1=foreground 0=background
        DrawPixel(m_cur_x+xc,m_cur_y+yc,col);         // set dot within bitmap
      }
    }
  }
  m_cur_x += (1==m_fnt_prop)?ch_width+1:m_fnt_width;  // proportional fonts get 1-pixel gap between chars
}

void COG_VLGEM1277::DrawString(const char *str, uint32_t typewriter){
  int32_t len=0;
  if((nullptr!=str) && (0!=(len=strlen(str)))) {
    for(int32_t ic=0; ic<len; ic++) {
      DrawChar(str[ic]);
      if(typewriter>0) { // simulate typewriter, i.e. update display with pause for every char
        RefreshLCD(); 
        delay(typewriter);
      }
    } 
    RefreshLCD(m_mod);
  }
}

// ----------------------------------------------------------------------------
// virtual functions, derived from Print class
// ------------------------------------------------------------------------

size_t COG_VLGEM1277::write(const uint8_t *buffer, size_t size){
  for(int32_t ic=0; ic<size; ic++) {
    write(buffer[ic]);
  } 
  return size;
}

size_t COG_VLGEM1277::write(const uint8_t character){
  DrawChar(character);
  return 1;
}

