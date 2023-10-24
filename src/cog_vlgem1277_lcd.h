#ifndef __COG_VLGEM1277_H__
#define __COG_VLGEM1277_H__

#include <Arduino.h>
#include <SPI.h>

// Model:     Varitronix VL-FS-COG-VLGEM1277 
// Size:      240x64 pixel 
// Driver-IC: ESPON S1D1572100B000 

constexpr int32_t LCD_WIDTH   = 240;      // number of pixels in width 
constexpr int32_t LCD_HEIGHT  =  64;      // number of pixels in height
constexpr int32_t LCD_N_PAGE  =  16;      // number of pages = height/4 
constexpr int32_t xMax = LCD_WIDTH-1;     // range x [0..239]
constexpr int32_t yMax = LCD_HEIGHT-1;    // range y [0..63]

// ESPON S1D1572100B000 init commands
constexpr uint8_t LCD_CMD_DATA_WRITE         = 0x1D;    // wr Display Data    (n-bytes)
constexpr uint8_t LCD_CMD_PAGE_ADDR          = 0xB1;    // wr Page Address    (2 byte)
constexpr uint8_t LCD_CMD_COL_ADDR           = 0x13;    // wr Column Address  (2 byte)
constexpr uint8_t LCD_CMD_DISPLAY_OFFON      = 0xAE;    // set Display ON/OFF: 0=Off/1=On
constexpr uint8_t LCD_CMD_DISPLAY_REVERSE    = 0xA6;    // set Display/Normal: 0=Normal/1=Reverse
constexpr uint8_t LCD_CMD_DISPLAY_ALL_LIGHT  = 0xA4;    // set Display All Lighting: 0=Normal/1=All On
constexpr uint8_t LCD_CMD_DISPLAY_START_LINE = 0x8A;    // set Display Start Line (2/3 byte)
constexpr uint8_t LCD_CMD_DISPLAY_MODE       = 0x66;    // set Display Mode (2 byte): 0=4 gray-scale, 1=binary
constexpr uint8_t LCD_CMD_GRAY_SCALE_PATTERN = 0x39;    // set Gray Scale Pattern (2 byte)
constexpr uint8_t LCD_CMD_COM_OUT_STATUS     = 0xC4;    // set Common Output Status Select: 0=Normal/1=Reverse
constexpr uint8_t LCD_CMD_DUTY_SET           = 0x6D;    // set Duty Command (3 byte)
constexpr uint8_t LCD_CMD_BUILTIN_OSC        = 0xAA;    // set Built-in Oscillator Circuit: [0]:0=Off/1=On
constexpr uint8_t LCD_CMD_BUILTIN_OSC_FREQ   = 0x5F;    // set Built-in Oscillator Circuit Frequency Select (2 byte)
constexpr uint8_t LCD_CMD_PWR_CONTROL        = 0x25;    // set Power Control (2 byte)
constexpr uint8_t LCD_CMD_LC_DRIVE_VOLTAGE   = 0x2B;    // set Liquid Crystal Drive Voltage Select (2 byte)
constexpr uint8_t LCD_CMD_EL_VOLUME          = 0x81;    // set Electronic Volume (2 byte)
constexpr uint8_t LCD_CMD_RESET              = 0xE2;    // do Software Reset

// 4 colors are possible, NONE for fill color
enum class col_e { NONE, WHITE, LIGHT_GREY, GREY, BLACK };

// automatic display refesh mode
enum class mod_e { autoRefresh_OFF, autoRefresh_ON };

// line pattern
enum class pat_e { solid, dotted };

// automatic line feed mode
enum class lf_e { autoLF_OFF, autoLF_ON };

// class COG_VLGEM1277 is derived from class Print, to inherit functions like printf()
class COG_VLGEM1277 : public Print {
  private:
    // GPIO pins 
    uint8_t m_cs;         // SPI chip select
    uint8_t m_mosi;       // SPI master-out-slave-in
    uint8_t m_clk;        // SPI clock
    uint8_t m_a0;         // A0 input cmd/data select

    // display buffer
    uint8_t *m_buf;       // display buffer
    uint16_t *m_buf16;    // 16bit ptr to display buffer

    // automatic refresh and automatic linefeed modes
    mod_e   m_mod;        // refresh-mode = [autoRefresh_OFF, autoRefresh_ON]
    lf_e    m_lf;         // line feed mode = [on, off]

    // draw parameters 
    int32_t m_cur_x;      // current cursor x position
    int32_t m_cur_y;      // current cursor y position
    col_e   m_edge_col;   // border color 
    col_e   m_fill_col;   // fill color
    pat_e   m_pat;        // line pattern [solid, dotted]

    // font parameters
    uint8_t *m_fnt;       // the current font-array
    int16_t m_fnt_hdr;    // the font header size
    int16_t m_fnt_width;  // char outline width
    int16_t m_fnt_height; // char outline height
    int16_t m_fnt_bpl;    // bytes per line
    int16_t m_fnt_bpc;    // bytes per character
    int16_t m_fnt_ch_s;   // start character
    int16_t m_fnt_ch_e;   // end character
    int16_t m_fnt_prop;   // 0=mono spaced 1=proportional 
    col_e m_fg_col;       // foreground drawing color
    col_e m_bg_col;       // background drawing color

    
  public:
    // constructor
    // @param cs   SPI chipselect pin
    // @param mosi SPI MOSI pin
    // @param clk  SPI clock pin
    // @param a0   A0 pin, cmd/data selector
    COG_VLGEM1277(uint8_t cs,uint8_t mosi,uint8_t clk,uint8_t a0);
    
    // - init SPI bus 
    // - init display
    void Begin(void);

    // compare and swap values if second is smaller than first
    // @param v0  first value
    // @param v1  second value
    inline void AdjustValues(int32_t &v0, int32_t &v1) { 
      if(v1<v0) {
        int32_t sw = v0;
        v0 = v1;
        v1 = sw;
      }
    }

    // set automatic line-feed mode
    // @param lf linefeed mode [lf_e::on, lf_e::off]
    inline void SetLfMode(lf_e lf) { m_lf=lf; }

    // fill Display with given color
    // @param color color to be filled, BLACK,GREY,LIGHT_GREY or WHITE
    void ClearScreen(col_e color=col_e::BLACK);

    // set foreground color
    // @param color  border color
    inline void SetBorderColor(col_e color) { m_edge_col=color; }
    
    // set background color
    // @param color  background color
    inline void SetFillColor(col_e color) { m_fill_col=color; }
    
    // set Font for Textoutput and foreground and background color
    // @param fnt     pointer to font array
    // @param col_fg  foreground color
    // @param col_bg  background color
    void SetFont(uint8_t* fnt,col_e col_fg=col_e::WHITE,col_e col_bg=col_e::BLACK);

    // get the first char in font
    // @return m_fnt_ch_s
    inline int16_t GetFontStartChar(void) { return m_fnt_ch_s; }
    
    // get the last char in font
    // @return m_fnt_ch_e
    inline int16_t GetFontEndChar(void) { return m_fnt_ch_e; }

    // get height of font chars
    // @return m_fnt_height
    inline int16_t GetFontHeight(void) { return m_fnt_height;}

    // get width of font chars
    // @return m_fnt_width
    inline int16_t GetFontWidth(void) { return m_fnt_width; }
    
    // set the current cursor position
    // @param x0 x-position
    // @param y0 y-position
    inline void SetCursor(int32_t x0, int32_t y0) { m_cur_x=x0; m_cur_y=y0; }

    // get current cursor x  position
    // @return m_xur_x  current x-position of cursor
    inline int32_t GetCursorX(void) { return m_cur_x; }
    
    // get the current y-position of cursor 
    // @return m_xur_x  current y-position of cursor
    inline int32_t GetCursorY(void) { return m_cur_y; }

    // draw pixel with given color or WHITE as default
    // @param x x-position
    // @param y y-position
    // @param color = [BLACK,GREY,LIGHT_GREY or WHITE]
    void DrawPixel(int32_t x0, int32_t y0, col_e color); 

    // draw pixel with border color
    // @param x x-position
    // @param y y-position
    inline void DrawPixel(int32_t x0, int32_t y0) { DrawPixel(x0,y0,m_edge_col); }

    // draw line in given color 
    // @param x0    start x-position
    // @param x1    end x-position
    // @param y0    start y-position
    // @param y1    end y-position
    // @param color = [BLACK,GREY,LIGHT_GREY or WHITE]
    void DrawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1, col_e color);

    // draw line with default color
    // @param x0    start x-position
    // @param x1    end x-position
    // @param y0    start y-position
    // @param y1    end y-position
    inline void DrawLine(int32_t x0, int32_t y0, int32_t x1, int32_t y1) {DrawLine(x0,y0,x1,y1,m_edge_col);}

    // draw horzontal line in given color or WHITE as default
    // @param x0    start x-position
    // @param x1    end x-position
    // @param y0    y-position
    // @param color = [BLACK,GREY,LIGHT_GREY or WHITE]
    // @param pattern = [solid,dotted]
    void DrawHline(int32_t x0, int32_t x1, int32_t y0, col_e color, pat_e pattern);

    // draw horzontal line with default color
    // @param x0    start x-position
    // @param x1    end x-position
    // @param y0    y-position
    inline void DrawHLine(int32_t x0, int32_t x1, int32_t y0) { DrawHline(x0,x1,y0,m_edge_col,m_pat); }

    // draw vertical line in given color or WHITE as default
    // @param x0    x-position
    // @param y0    start y-position
    // @param y1    end y-position
    // @param color = [BLACK,GREY,LIGHT_GREY or WHITE]
    void DrawVline(int32_t x0, int32_t y0, int32_t y1, col_e color, pat_e pattern);

    // draw vertical line with default color
    // @param x0    x-position
    // @param y0    start y-position
    // @param y1    end y-position
    inline void DrawVline(int32_t x0, int32_t y0, int32_t y1) { DrawVline(x0,y0,y1,m_edge_col,m_pat); }

    // draw rectangle in given colors, default frame=WHITE and filling=BLACK
    // @param x0    start x-position
    // @param x1    end x-position
    // @param y0    start y-position
    // @param y1    end y-position
    // @param border_color = [BLACK,GREY,LIGHT_GREY or WHITE]
    // @param fill_color   = [BLACK,GREY,LIGHT_GREY or WHITE]
    // @param pattern = [solid,dotted]
    void DrawRect(int32_t x0, int32_t y0, int32_t x1, int32_t y1, col_e border_color, col_e fill_color, pat_e pattern);

    // draw rectangle with default colors
    // @param x0    start x-position
    // @param x1    end x-position
    // @param y0    start y-position
    // @param y1    end y-position
    inline void DrawRect(int32_t x0, int32_t y0, int32_t x1, int32_t y1) { DrawRect(x0,y0,x1,y1,m_edge_col,m_fill_col,m_pat); }


    // draw rectangle with border color WHITE with no filling
    // @param x0     start x-position
    // @param y0     start y-position
    // @param x1     end x-position
    // @param y1     end y-position
    // @param pat    = [solid,dotted]
    void DrawBox(int32_t x0, int32_t y0, int32_t x1, int32_t y1, pat_e pat);

    // draw circle at pos (x0,y0) with radius rad in given colors, default frame=WHITE and filling=BLACK
    // @param x0    center x position
    // @param y0    center y-position
    // @param rad   radius
    // @param border_color = [BLACK,GREY,LIGHT_GREY or WHITE]
    // @param fill_color   = [BLACK,GREY,LIGHT_GREY or WHITE]
    void DrawCircle(int32_t x0, int32_t y0, int32_t rad, col_e border_color, col_e fill_color);

    // draw circle at pos (x0,y0) with radius rad and default colors
    // @param x0    center x position
    // @param y0    center y-position
    // @param rad   radius
    inline void DrawCircle(int32_t x0, int32_t y0, int32_t rad) { DrawCircle(x0,y0,rad,m_edge_col,m_fill_col); }

    // draw a single character at the current cursor position, checks if ch is in range. Do a auto cr-lf 
    // if right border is reached and do do a srcoll if bottom is reached, and set the cursor postion accordingly
    // @param ch character 
    void DrawChar(uint8_t ch);
    
    // draw a string at the current cursor position, calls the DrawChar function, with auto cr-lf and 
    // auto-scrolling
    // @param str string to be printed
    // @param typewrite delay like typewriter
    void DrawString(const char *str,uint32_t typewriter=0);

    // srcolls by 4 pixels, i.e for all a 8 pixel height font use Scroll(2) to scroll a complete line
    void Scroll(void);
    
    // set auto update mode
    // @param mode = [autoRefresh_OFF, autoRefresh_ON]
    inline void SetRefreshMode(mod_e mode) {m_mod = mode;}
    
    // get current update mode
    // @return m_mod = [autoRefresh_OFF, autoRefresh_ON]
    inline mod_e GetRefreshMode(void) { return m_mod; }

    // if mode==autoRefresh_ON, then the complete buffer is copied to the display. (refresh)
    // To force an refresh, the RefreshLCD() function can be called without parameter
    // @param mode [autoRefresh_OFF, autoRefresh_ON]
    void RefreshLCD(mod_e mode=mod_e::autoRefresh_ON);
  
  protected:
    // write Data (1 Byte), CS=low A0=high
    // @param data byte to be written
    void WrData(uint8_t data);

    // write Data 16-Bit wise (a complete page)
    // @param buf16 16bit pointer to start 
    // @param len   number of words to be written 
    void WrPage(uint16_t* buf16, int32_t len);

    // write Command , CS=low A0=low
    // @param cmd  command to be written
    void WrCmd(uint8_t cmd);

    // write Command with 1 argument, CS=low A0=low
    // @param cmd command to be written
    // @param arg argument of command
    void WrCmd(uint8_t cmd, uint8_t arg);

    // write Command with 2 arguments, CS=low A0=low
    // @param cmd command to be written
    // @param arg1 first argument of command
    // @param arg2 second argument of command
    void WrCmd(uint8_t cmd, uint8_t arg1, uint8_t arg2);
    
    
    // ------------------------------------------------------------------------
    // virtual functions, derived from Print class
    // ------------------------------------------------------------------------
    
    // virtual function, used by print class, writes a single character
    // @param character single character
    // @return number of characters written
    virtual size_t write(const uint8_t character);
    
    // virtual function, used by print class, writes a  character string
    // @param buffer input character string 
    // @param size of character string
    // @return number of characters written
    virtual size_t write(const uint8_t *buffer, size_t size);

};

#endif
//__COG_VLGEM1277_H__
