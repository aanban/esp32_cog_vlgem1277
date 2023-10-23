#include <Arduino.h>
#include <SPI.h>
#include "cog_vlgem1277_lcd.h"
#include "font_mono6x8.h"
#include "font_mono8x14.h"
#include "font_sans6x8.h"
#include "font_nusstorte6x8.h"
#include "font_nusstorte6x8w.h"

// Varitronix COG_VLGEM1277 LCD
constexpr uint8_t PIN_CS   =  5;  // PB2: CS    (LCD[/CS]: Chip-Enable, low-active)
constexpr uint8_t PIN_SCK  = 18;  // PB5: SCK   (LCD[SCL]: Serial Clock)
constexpr uint8_t PIN_MOSI = 23;  // PB3: MOSI  (LCD[SI]:  Data In)
constexpr uint8_t PIN_A0   = 17;  // PD3: A0    (LCD[A0]:  LSB of Adress Bus: 0=Commands/1=Data)

COG_VLGEM1277 lcd(PIN_CS,PIN_SCK,PIN_MOSI,PIN_A0);

// dummy text
static const char bt00[] =
  "\n\nDies ist ein Typoblindtext. An ihm kann man sehen, ob alle Buchstaben "
  "da sind und wie sie aussehen. Manchmal benutzt man Worte wie Hamburgefonts, " 
  "Rafgenduks oder Handgloves, um Schriften zu testen. Er versuchte, sich in "
  "der Dunkelheit seinen Weg zu ertasten und erstarrte.\n" 
  "1 abcdefghijklmnopqrstuvwxyz+-/.;\n"
  "2 ABCDEFGHIJKLMNOPQRSTUVWXYZ+-/.;\n"
  "4 ----------1---------2---------3\n"
  "3 0123456789.123456789.123456789.\n"  
  "5 aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOp\n"
  "6 AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoP\n"
  "7 1a2b3c4d5e6f7g8h9i0j1k2l3m4n5o6\n"
  "8 HandglovesHamburgefontsRafgendu"
  ;

void draw_title(const char *title){
  lcd.ClearScreen();
  lcd.SetFont((uint8_t *)Sans6x8,col_e::BLACK,col_e::WHITE); 
  lcd.DrawString(title); 
  lcd.SetCursor(0,16);
  lcd.RefreshLCD();
}

void font_alphabet(void){
  uint8_t ic=0; 
  mod_e auto_mode=lcd.GetRefreshMode();       // get current auto-refresh-mode
  uint8_t fnt_ch_s=lcd.GetFontStartChar();    // start char
  uint8_t fnt_ch_e=lcd.GetFontEndChar();      // end char
  lcd.SetRefreshMode(mod_e::autoRefresh_OFF); // stop auto-refresh
  
  for(ic=fnt_ch_s;ic<fnt_ch_e;ic++){          // draw complete char set
    lcd.DrawChar(ic); 
    if(31==(ic%32)) lcd.DrawChar('\n');
  }
  lcd.RefreshLCD(); // force refresh
  lcd.SetRefreshMode(auto_mode);
}

void test_font(uint8_t *font, const char *Name, const char *txt) {
  lcd.ClearScreen();
  lcd.SetRefreshMode(mod_e::autoRefresh_ON);
  lcd.SetFont(font);
  lcd.SetCursor(0,0);
  lcd.printf("%s %dx%d ch[%d-%d]\n",Name,lcd.GetFontWidth(),lcd.GetFontHeight(),lcd.GetFontStartChar(),lcd.GetFontEndChar());
  font_alphabet();
  delay(4000);
  lcd.DrawString(txt,50); // print text typewriter
  delay(4000);
}

void test_rectangle(void) {
  // lcd.ClearScreen();
  // lcd.SetRefreshMode(mod_e::autoRefresh_ON); // automatic refresh 
  // lcd.DrawRect(0,0,xMax,63);
  // for (uint32_t ic=0;ic<240;ic+=6)  lcd.DrawVline( ic,0,63);
  // for (uint32_t ic=0;ic<64; ic+=8)  lcd.DrawHline(0,240,ic);
  // delay(3000);
  // lcd.ClearScreen();
  // lcd.SetRefreshMode(mod_e::autoRefresh_ON); // automatic refresh 
  // lcd.DrawRect(0,0,xMax,63,col_e::WHITE,col_e::BLACK,pat_e::dotted);
  // for (uint32_t ic=0;ic<240;ic+=6) lcd.DrawVline( ic,0,63,col_e::WHITE,pat_e::dotted);
  // for (uint32_t ic=0;ic<64; ic+=8) lcd.DrawHline(0,xMax,ic,col_e::WHITE,pat_e::dotted);
  // delay(3000);
  lcd.ClearScreen();
  lcd.SetRefreshMode(mod_e::autoRefresh_ON); // automatic refresh 
  lcd.SetFont((uint8_t *)Sans6x8); lcd.SetCursor(2,2); lcd.printf("rectangle test");
  lcd.DrawRect( 0,18,98,32);
  lcd.DrawRect( 2,20,12,30);
  lcd.DrawRect(14,20,24,30);
  lcd.DrawRect(26,20,36,30);
  lcd.DrawRect(38,20,48,30);
  lcd.DrawRect(50,20,60,30);
  lcd.DrawRect(62,20,72,30);
  lcd.DrawRect(74,20,84,30);
  lcd.DrawRect(86,20,96,30);
  lcd.SetFont((uint8_t *)Sans6x8); lcd.SetCursor(102,20); lcd.printf("10x10");
  lcd.DrawRect(  0,38,98,52,col_e::WHITE,col_e::BLACK,pat_e::solid);
  lcd.DrawRect(  2,40,12,50,col_e::WHITE,col_e::BLACK,pat_e::dotted);
  lcd.DrawRect( 14,40,24,50,col_e::WHITE,col_e::BLACK,pat_e::dotted);
  lcd.DrawRect( 26,40,36,50,col_e::WHITE,col_e::BLACK,pat_e::dotted);
  lcd.DrawRect( 38,40,48,50,col_e::WHITE,col_e::BLACK,pat_e::dotted);
  lcd.DrawRect( 50,40,60,50,col_e::WHITE,col_e::BLACK,pat_e::dotted);
  lcd.DrawRect( 62,40,72,50,col_e::WHITE,col_e::BLACK,pat_e::dotted);
  lcd.DrawRect( 74,40,84,50,col_e::WHITE,col_e::BLACK,pat_e::dotted);
  lcd.DrawRect( 86,40,96,50,col_e::WHITE,col_e::BLACK,pat_e::dotted);
  lcd.SetFont((uint8_t *)Sans6x8); lcd.SetCursor(102,40); lcd.printf("dotted");
  lcd.RefreshLCD();
  delay(2000);
  lcd.SetFont((uint8_t *)Sans6x8); lcd.SetCursor(2,2); lcd.printf("circle test     ");
  lcd.DrawCircle(190,30,25,col_e::WHITE,col_e::GREY); delay(1000);
  lcd.DrawCircle(190,30,20);delay(1000);
  lcd.DrawCircle(190,30,15,col_e::WHITE,col_e::GREY); delay(1000);
  lcd.DrawCircle(190,30,10,col_e::WHITE,col_e::BLACK);delay(1000);
  lcd.RefreshLCD();
  delay(2000);
}

void test_ruler_font(uint8_t *font, const char* title) {
  lcd.ClearScreen();
  lcd.SetRefreshMode(mod_e::autoRefresh_ON); // automatic refresh 
  lcd.SetFont(font); 
  lcd.SetLfMode(lf_e::autoLF_OFF); // auto-linefeed off
  lcd.SetCursor(0,0); 
  for(int32_t xc=0; xc<LCD_WIDTH; xc+=6) {
    for(int32_t yc=0; yc<LCD_HEIGHT; yc+=8) {
      lcd.DrawPixel(xc,yc);
    }
  }
  lcd.SetCursor(12,16);
  lcd.printf("%s",title);
  lcd.SetCursor(0,24); 
  lcd.printf("0---------1---------2---------3---------4---------5---------6\n");
  lcd.RefreshLCD();
  lcd.SetCursor(0,32); 
  lcd.printf("abcdefghijklmnopqrstuvwxyzABCDEFGHJKLMNOPQRSTUVWXYZabcefghijk\n");
  lcd.RefreshLCD();
  delay(5000);
  lcd.SetCursor(0,24); 
  lcd.printf("0123456789-123456789-123456789-123456789-123456789-123456789-\n");
  lcd.RefreshLCD();
  delay(5000);
}

void test_lines(void) {
  lcd.ClearScreen();
  lcd.DrawRect(0,0,xMax,63);
  lcd.SetFont((uint8_t *)Sans6x8); lcd.SetCursor(2,2); lcd.printf("test lines");
  lcd.RefreshLCD();
  delay(1000);
  lcd.SetRefreshMode(mod_e::autoRefresh_OFF);
  lcd.DrawRect(0,0,xMax,63);
  for(uint8_t kc=0;kc<3;kc++) {
    lcd.SetRefreshMode(mod_e::autoRefresh_ON); // automatic refresh 
    for (uint8_t ic=0;ic<240;ic+=10) { lcd.DrawLine(119,31,ic,0);       }
    for (uint8_t ic=0;ic< 64;ic+= 8) { lcd.DrawLine(119,31,xMax,ic);    }
    for (uint8_t ic=0;ic<240;ic+=10) { lcd.DrawLine(119,31,xMax-ic,63); }
    for (uint8_t ic=0;ic< 64;ic+= 8) { lcd.DrawLine(119,31,0,63-ic);    }
    delay(1000);
    for (uint8_t ic=0;ic<240;ic+=10) { lcd.DrawLine(119,31, ic,0,col_e::BLACK);     }
    lcd.DrawLine(0,0,xMax,0);
    for (uint8_t ic=0;ic< 64;ic+= 8) { lcd.DrawLine(119,31,xMax,ic,col_e::BLACK);    }
    lcd.DrawLine(xMax,0,xMax,63);
    for (uint8_t ic=0;ic<240;ic+=10) { lcd.DrawLine(119,31,xMax-ic,63,col_e::BLACK); }
    lcd.DrawLine(xMax,63,0,63);
    for (uint8_t ic=0;ic< 64;ic+= 8) { lcd.DrawLine(119,31,0,63-ic,col_e::BLACK);    }
    lcd.DrawLine(0,63,0,0);
    delay(1000);
  }
}

void setup() {
  //Serial.begin(115200);
  //printf("lcd.Begin()\n");
  lcd.Begin();
}

void loop() {
  test_font((uint8_t*)Mono6x8,      "test font Mono6x8",      bt00);
  test_font((uint8_t*)Sans6x8,      "test font Sans6x8",      bt00);
  test_ruler_font((uint8_t*)Mono6x8,      "test ruler font Mono6x8");
  test_ruler_font((uint8_t*)Nusstorte6x8w,"test ruler font Nusstorte6x8w");
  test_rectangle();
  test_lines();
}