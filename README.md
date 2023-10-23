# esp32_cog_vlgem1277

This library consist of a LCD driver for the Varitronix COG-VLGEM1277-01 Display that is currently available hat [pollin.de](https://www.pollin.de/p/varitronix-lcd-cog-vlgem1277-01-240x64-pixel-121713)


More Information about how to connect to a µC can be found at [mikrocontroller.netk](https://www.mikrocontroller.net/topic/472549)

# example

```c

#include <Arduino.h>
#include <SPI.h>
#include "cog_vlgem1277_lcd.h"
#include "font_mono6x8.h"

// Varitronix COG_VLGEM1277 LCD
constexpr uint8_t PIN_CS   =  5;  // PB2: CS    (LCD[/CS]: Chip-Enable, low-active)
constexpr uint8_t PIN_SCK  = 18;  // PB5: SCK   (LCD[SCL]: Serial Clock)
constexpr uint8_t PIN_MOSI = 23;  // PB3: MOSI  (LCD[SI]:  Data In)
constexpr uint8_t PIN_A0   = 17;  // PD3: A0    (LCD[A0]:  LSB of Adress Bus: 0=Commands/1=Data)

COG_VLGEM1277 lcd(PIN_CS,PIN_SCK,PIN_MOSI,PIN_A0);


void test_rectangle(void) {
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
  lcd.Begin();
}

void loop() {
  test_rectangle();
  test_lines();
}

```