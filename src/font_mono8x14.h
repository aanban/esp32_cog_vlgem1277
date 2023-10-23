//FontName: terminal8x14
//FontSize: 8 x 14

const uint8_t Mono8x14[] = {
  17,  // offset 8*2 + 1
  8,   // width
  14,  // height
  2,   // bytes per line
  32,  // first char
  127, // last char
  0,   // 0 = fixed pitch
  
  0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char  
  0x06, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0xFC, 0x06, 0xFC, 0x06, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char !
  0x07, 0x00, 0x00, 0x1C, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x1C, 0x00, 0x00, 0x00,  // Code for char "
  0x08, 0x00, 0x00, 0x10, 0x01, 0xFC, 0x07, 0xFC, 0x07, 0x10, 0x01, 0xFC, 0x07, 0xFC, 0x07, 0x10, 0x01,  // Code for char #
  0x07, 0x00, 0x00, 0x18, 0x02, 0x3C, 0x06, 0x67, 0x1C, 0xC7, 0x1C, 0x8C, 0x07, 0x08, 0x03, 0x00, 0x00,  // Code for char $
  0x08, 0x0C, 0x00, 0x1E, 0x03, 0x92, 0x01, 0xDE, 0x06, 0x6C, 0x0F, 0x30, 0x09, 0x18, 0x0F, 0x00, 0x06,  // Code for char %
  0x08, 0x00, 0x00, 0xD8, 0x03, 0xFC, 0x07, 0x24, 0x04, 0xBC, 0x04, 0x98, 0x03, 0x80, 0x07, 0x80, 0x04,  // Code for char &
  0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char '
  0x06, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x03, 0xF8, 0x0F, 0x1C, 0x1C, 0x04, 0x10, 0x00, 0x00, 0x00, 0x00,  // Code for char (
  0x06, 0x00, 0x00, 0x00, 0x00, 0x04, 0x10, 0x1C, 0x1C, 0xF8, 0x0F, 0xE0, 0x03, 0x00, 0x00, 0x00, 0x00,  // Code for char )
  0x08, 0x00, 0x00, 0x40, 0x00, 0x50, 0x01, 0xF0, 0x01, 0xE0, 0x00, 0xF0, 0x01, 0x50, 0x01, 0x40, 0x00,  // Code for char *
  0x07, 0x00, 0x00, 0x40, 0x00, 0x40, 0x00, 0xF0, 0x01, 0xF0, 0x01, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00,  // Code for char +
  0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x00, 0x1E, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00,  // Code for char ,
  0x07, 0x00, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00,  // Code for char -
  0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00,  // Code for char .
  0x07, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x0F, 0xC0, 0x03, 0xF0, 0x00, 0x3C, 0x00, 0x0C, 0x00, 0x00, 0x00,  // Code for char /
  0x08, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x03, 0xFC, 0x07, 0x84, 0x05, 0x34, 0x04, 0xFC, 0x07, 0xF8, 0x03,  // Code for char 0
  0x06, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00, 0x18, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x00, 0x00, 0x00, 0x00,  // Code for char 1
  0x07, 0x00, 0x00, 0x18, 0x06, 0x1C, 0x07, 0x84, 0x05, 0xC4, 0x04, 0x7C, 0x04, 0x38, 0x04, 0x00, 0x00,  // Code for char 2
  0x07, 0x00, 0x00, 0x18, 0x03, 0x1C, 0x07, 0x44, 0x04, 0x44, 0x04, 0xFC, 0x07, 0xB8, 0x03, 0x00, 0x00,  // Code for char 3
  0x08, 0x00, 0x00, 0x80, 0x01, 0xFC, 0x01, 0x7C, 0x01, 0x00, 0x01, 0xF0, 0x07, 0xF0, 0x07, 0x00, 0x01,  // Code for char 4
  0x07, 0x00, 0x00, 0x7C, 0x04, 0x7C, 0x04, 0x44, 0x04, 0x44, 0x06, 0xC4, 0x03, 0x84, 0x01, 0x00, 0x00,  // Code for char 5
  0x07, 0x00, 0x00, 0xE0, 0x03, 0xF0, 0x07, 0x3C, 0x04, 0x2C, 0x04, 0xE4, 0x07, 0xC0, 0x03, 0x00, 0x00,  // Code for char 6
  0x07, 0x00, 0x00, 0x04, 0x00, 0x04, 0x07, 0xC4, 0x07, 0xF4, 0x00, 0x3C, 0x00, 0x0C, 0x00, 0x00, 0x00,  // Code for char 7
  0x07, 0x00, 0x00, 0xB8, 0x03, 0xFC, 0x07, 0x64, 0x04, 0xC4, 0x04, 0xFC, 0x07, 0xB8, 0x03, 0x00, 0x00,  // Code for char 8
  0x07, 0x00, 0x00, 0x78, 0x00, 0xFC, 0x04, 0x84, 0x06, 0x84, 0x07, 0xFC, 0x01, 0xF8, 0x00, 0x00, 0x00,  // Code for char 9
  0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x06, 0x30, 0x06, 0x30, 0x06, 0x00, 0x00, 0x00, 0x00,  // Code for char :
  0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x16, 0x30, 0x1E, 0x30, 0x0E, 0x00, 0x00, 0x00, 0x00,  // Code for char ;
  0x07, 0x00, 0x00, 0x40, 0x00, 0xE0, 0x00, 0xB0, 0x01, 0x18, 0x03, 0x0C, 0x06, 0x04, 0x04, 0x00, 0x00,  // Code for char <
  0x07, 0x00, 0x00, 0xA0, 0x00, 0xA0, 0x00, 0xA0, 0x00, 0xA0, 0x00, 0xA0, 0x00, 0xA0, 0x00, 0x00, 0x00,  // Code for char =
  0x07, 0x00, 0x00, 0x04, 0x04, 0x0C, 0x06, 0x18, 0x03, 0xB0, 0x01, 0xE0, 0x00, 0x40, 0x00, 0x00, 0x00,  // Code for char >
  0x07, 0x00, 0x00, 0x18, 0x00, 0x1C, 0x00, 0xC4, 0x06, 0xE4, 0x06, 0x3C, 0x00, 0x18, 0x00, 0x00, 0x00,  // Code for char ?
  0x08, 0xF8, 0x03, 0xFC, 0x07, 0x04, 0x04, 0xC4, 0x04, 0xE4, 0x05, 0x24, 0x05, 0xFC, 0x05, 0xF8, 0x05,  // Code for char @
  0x07, 0x00, 0x00, 0xF0, 0x07, 0xF8, 0x07, 0x8C, 0x00, 0x8C, 0x00, 0xF8, 0x07, 0xF0, 0x07, 0x00, 0x00,  // Code for char A
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x44, 0x04, 0x44, 0x04, 0xFC, 0x07, 0xB8, 0x03, 0x00, 0x00,  // Code for char B
  0x07, 0x00, 0x00, 0xF8, 0x03, 0xFC, 0x07, 0x04, 0x04, 0x04, 0x04, 0x1C, 0x07, 0x18, 0x03, 0x00, 0x00,  // Code for char C
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x04, 0x04, 0x0C, 0x06, 0xF8, 0x03, 0xF0, 0x01, 0x00, 0x00,  // Code for char D
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x44, 0x04, 0x44, 0x04, 0x44, 0x04, 0x04, 0x04, 0x00, 0x00,  // Code for char E
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x44, 0x00, 0x44, 0x00, 0x44, 0x00, 0x04, 0x00, 0x00, 0x00,  // Code for char F
  0x07, 0x00, 0x00, 0xF8, 0x03, 0xFC, 0x07, 0x04, 0x04, 0x84, 0x04, 0x9C, 0x07, 0x98, 0x07, 0x00, 0x00,  // Code for char G
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x40, 0x00, 0x40, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x00, 0x00,  // Code for char H
  0x06, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0xFC, 0x07, 0xFC, 0x07, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00,  // Code for char I
  0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x07, 0x00, 0x04, 0x00, 0x04, 0xFC, 0x07, 0xFC, 0x03, 0x00, 0x00,  // Code for char J
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x40, 0x00, 0xF0, 0x01, 0xBC, 0x07, 0x0C, 0x06, 0x00, 0x00,  // Code for char K
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00,  // Code for char L
  0x08, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x10, 0x00, 0xE0, 0x00, 0x10, 0x00, 0xFC, 0x07, 0xFC, 0x07,  // Code for char M
  0x08, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x30, 0x00, 0x60, 0x00, 0xC0, 0x00, 0xFC, 0x07, 0xFC, 0x07,  // Code for char N
  0x07, 0x00, 0x00, 0xF8, 0x03, 0xFC, 0x07, 0x04, 0x04, 0x04, 0x04, 0xFC, 0x07, 0xF8, 0x03, 0x00, 0x00,  // Code for char O
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x44, 0x00, 0x44, 0x00, 0x7C, 0x00, 0x38, 0x00, 0x00, 0x00,  // Code for char P
  0x07, 0x00, 0x00, 0xF8, 0x03, 0xFC, 0x07, 0x04, 0x04, 0x04, 0x0C, 0xFC, 0x1F, 0xF8, 0x13, 0x00, 0x00,  // Code for char Q
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x44, 0x00, 0xC4, 0x00, 0xFC, 0x07, 0x38, 0x07, 0x00, 0x00,  // Code for char R
  0x07, 0x00, 0x00, 0x18, 0x02, 0x3C, 0x06, 0x64, 0x04, 0xC4, 0x04, 0x8C, 0x07, 0x08, 0x03, 0x00, 0x00,  // Code for char S
  0x07, 0x00, 0x00, 0x04, 0x00, 0x04, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00,  // Code for char T
  0x07, 0x00, 0x00, 0xFC, 0x03, 0xFC, 0x07, 0x00, 0x04, 0x00, 0x04, 0xFC, 0x07, 0xFC, 0x03, 0x00, 0x00,  // Code for char U
  0x07, 0x00, 0x00, 0xFC, 0x01, 0xFC, 0x03, 0x00, 0x06, 0x00, 0x06, 0xFC, 0x03, 0xFC, 0x01, 0x00, 0x00,  // Code for char V
  0x08, 0x00, 0x00, 0xFC, 0x00, 0xFC, 0x07, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x07, 0xFC, 0x07, 0xFC, 0x00,  // Code for char W
  0x07, 0x00, 0x00, 0x0C, 0x07, 0x9C, 0x07, 0x70, 0x00, 0xE0, 0x00, 0x9C, 0x07, 0x0C, 0x07, 0x00, 0x00,  // Code for char X
  0x07, 0x00, 0x00, 0x3C, 0x00, 0x7C, 0x00, 0xC0, 0x07, 0xC0, 0x07, 0x7C, 0x00, 0x3C, 0x00, 0x00, 0x00,  // Code for char Y
  0x07, 0x00, 0x00, 0x04, 0x07, 0x84, 0x07, 0xC4, 0x04, 0x64, 0x04, 0x3C, 0x04, 0x1C, 0x04, 0x00, 0x00,  // Code for char Z
  0x06, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x3F, 0xFC, 0x3F, 0x04, 0x20, 0x04, 0x20, 0x00, 0x00, 0x00, 0x00,  // Code for char [
  0x07, 0x00, 0x00, 0x0C, 0x00, 0x3C, 0x00, 0xF0, 0x00, 0xC0, 0x03, 0x00, 0x0F, 0x00, 0x0C, 0x00, 0x00,  // Code for char BackSlash
  0x06, 0x00, 0x00, 0x00, 0x00, 0x04, 0x20, 0x04, 0x20, 0xFC, 0x3F, 0xFC, 0x3F, 0x00, 0x00, 0x00, 0x00,  // Code for char ]
  0x07, 0x00, 0x00, 0x04, 0x00, 0x06, 0x00, 0x03, 0x00, 0x03, 0x00, 0x06, 0x00, 0x04, 0x00, 0x00, 0x00,  // Code for char ^
  0x08, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20,  // Code for char _
  0x06, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x07, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char `
  0x07, 0x00, 0x00, 0x00, 0x03, 0x90, 0x07, 0x90, 0x04, 0x90, 0x04, 0xF0, 0x07, 0xE0, 0x07, 0x00, 0x00,  // Code for char a
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x10, 0x04, 0x10, 0x04, 0xF0, 0x07, 0xE0, 0x03, 0x00, 0x00,  // Code for char b
  0x07, 0x00, 0x00, 0xE0, 0x03, 0xF0, 0x07, 0x10, 0x04, 0x10, 0x04, 0x30, 0x06, 0x20, 0x02, 0x00, 0x00,  // Code for char c
  0x07, 0x00, 0x00, 0xE0, 0x03, 0xF0, 0x07, 0x10, 0x04, 0x10, 0x04, 0xFC, 0x07, 0xFC, 0x07, 0x00, 0x00,  // Code for char d
  0x07, 0x00, 0x00, 0xE0, 0x03, 0xF0, 0x07, 0x90, 0x04, 0x90, 0x04, 0xF0, 0x04, 0xE0, 0x00, 0x00, 0x00,  // Code for char e
  0x07, 0x00, 0x00, 0x40, 0x00, 0xF8, 0x07, 0xFC, 0x07, 0x44, 0x00, 0x44, 0x00, 0x44, 0x00, 0x00, 0x00,  // Code for char f
  0x07, 0x00, 0x00, 0xE0, 0x23, 0xF0, 0x27, 0x10, 0x24, 0x10, 0x24, 0xF0, 0x3F, 0xF0, 0x1F, 0x00, 0x00,  // Code for char g
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x10, 0x00, 0x10, 0x00, 0xF0, 0x07, 0xE0, 0x07, 0x00, 0x00,  // Code for char h
  0x07, 0x00, 0x00, 0x10, 0x04, 0x10, 0x04, 0xF6, 0x07, 0xF6, 0x07, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00,  // Code for char i
  0x06, 0x00, 0x00, 0x00, 0x20, 0x10, 0x20, 0x10, 0x20, 0xF6, 0x3F, 0xF6, 0x1F, 0x00, 0x00, 0x00, 0x00,  // Code for char j
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0x80, 0x00, 0xC0, 0x01, 0x70, 0x07, 0x30, 0x06, 0x00, 0x00,  // Code for char k
  0x07, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0xFC, 0x07, 0xFC, 0x07, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00,  // Code for char l
  0x08, 0x00, 0x00, 0xF0, 0x07, 0xF0, 0x07, 0x10, 0x00, 0xF0, 0x03, 0x10, 0x00, 0xF0, 0x07, 0xE0, 0x07,  // Code for char m
  0x07, 0x00, 0x00, 0xF0, 0x07, 0xF0, 0x07, 0x10, 0x00, 0x10, 0x00, 0xF0, 0x07, 0xE0, 0x07, 0x00, 0x00,  // Code for char n
  0x07, 0x00, 0x00, 0xE0, 0x03, 0xF0, 0x07, 0x10, 0x04, 0x10, 0x04, 0xF0, 0x07, 0xE0, 0x03, 0x00, 0x00,  // Code for char o
  0x07, 0x00, 0x00, 0xF0, 0x3F, 0xF0, 0x3F, 0x10, 0x04, 0x10, 0x04, 0xF0, 0x07, 0xE0, 0x03, 0x00, 0x00,  // Code for char p
  0x07, 0x00, 0x00, 0xE0, 0x03, 0xF0, 0x07, 0x10, 0x04, 0x10, 0x04, 0xF0, 0x3F, 0xF0, 0x3F, 0x00, 0x00,  // Code for char q
  0x07, 0x00, 0x00, 0xF0, 0x07, 0xF0, 0x07, 0x40, 0x00, 0x20, 0x00, 0x30, 0x00, 0x30, 0x00, 0x00, 0x00,  // Code for char r
  0x07, 0x00, 0x00, 0x60, 0x04, 0xF0, 0x04, 0x90, 0x04, 0x90, 0x04, 0x90, 0x07, 0x10, 0x03, 0x00, 0x00,  // Code for char s
  0x07, 0x00, 0x00, 0x10, 0x00, 0xFC, 0x03, 0xFC, 0x07, 0x10, 0x04, 0x10, 0x04, 0x10, 0x04, 0x00, 0x00,  // Code for char t
  0x07, 0x00, 0x00, 0xF0, 0x03, 0xF0, 0x07, 0x00, 0x04, 0x00, 0x04, 0xF0, 0x07, 0xF0, 0x07, 0x00, 0x00,  // Code for char u
  0x07, 0x00, 0x00, 0xF0, 0x01, 0xF0, 0x03, 0x00, 0x06, 0x00, 0x06, 0xF0, 0x03, 0xF0, 0x01, 0x00, 0x00,  // Code for char v
  0x08, 0x00, 0x00, 0xF0, 0x01, 0xF0, 0x07, 0x00, 0x06, 0xE0, 0x01, 0x00, 0x06, 0xF0, 0x07, 0xF0, 0x01,  // Code for char w
  0x07, 0x00, 0x00, 0x30, 0x06, 0x70, 0x07, 0xC0, 0x01, 0xC0, 0x01, 0x70, 0x07, 0x30, 0x06, 0x00, 0x00,  // Code for char x
  0x07, 0x00, 0x20, 0xF0, 0x23, 0xF0, 0x27, 0x00, 0x34, 0x00, 0x1C, 0xF0, 0x0F, 0xF0, 0x03, 0x00, 0x00,  // Code for char y
  0x07, 0x00, 0x00, 0x10, 0x06, 0x10, 0x07, 0x90, 0x05, 0xD0, 0x04, 0x70, 0x04, 0x30, 0x04, 0x00, 0x00,  // Code for char z
  0x06, 0x00, 0x00, 0x80, 0x00, 0xC0, 0x01, 0x78, 0x0F, 0x3C, 0x1E, 0x04, 0x10, 0x00, 0x00, 0x00, 0x00,  // Code for char {
  0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x3F, 0xFC, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char |
  0x07, 0x00, 0x00, 0x00, 0x00, 0x04, 0x10, 0x3C, 0x1E, 0x78, 0x0F, 0xC0, 0x01, 0x80, 0x00, 0x00, 0x00,  // Code for char }
  0x08, 0x18, 0x00, 0x0C, 0x00, 0x04, 0x00, 0x0C, 0x00, 0x18, 0x00, 0x10, 0x00, 0x18, 0x00, 0x0C, 0x00,  // Code for char ~
  0x07, 0x00, 0x00, 0xFC, 0x07, 0xFC, 0x07, 0xFC, 0x07, 0xFC, 0x07, 0xFC, 0x07, 0xFC, 0x07, 0x00, 0x00   // Code for char 
};

