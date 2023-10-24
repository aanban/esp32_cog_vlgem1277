// GLCD FontName : Nusstorte_mono6x8 wide 
// GLCD FontSize : 6 x 8
// proportional font

const uint8_t Square6x8[] = {
  7,   // offset 6*1 + 1
  6,   // width
  8,   // height
  1,   // bytes per font column
  32,  // first char
  127, // last char
  1,   // 0=mono spaced 1=proportional
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // Code for char  
  0x03, 0x00, 0x00, 0x5F, 0x00, 0x00, 0x00,  // Code for char !
  0x05, 0x07, 0x03, 0x00, 0x07, 0x03, 0x00,  // Code for char "
  0x05, 0x14, 0x3E, 0x14, 0x3E, 0x14, 0x00,  // Code for char #
  0x05, 0x2E, 0x2A, 0x7F, 0x2A, 0x3A, 0x00,  // Code for char $
  0x05, 0x63, 0x13, 0x08, 0x64, 0x63, 0x00,  // Code for char %
  0x05, 0x37, 0x49, 0x57, 0x20, 0x50, 0x00,  // Code for char &
  0x03, 0x00, 0x07, 0x03, 0x00, 0x00, 0x00,  // Code for char '
  0x03, 0x3E, 0x41, 0x41, 0x00, 0x00, 0x00,  // Code for char (
  0x04, 0x00, 0x41, 0x41, 0x3E, 0x00, 0x00,  // Code for char )
  0x05, 0x08, 0x3E, 0x1C, 0x3E, 0x08, 0x00,  // Code for char *
  0x05, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00,  // Code for char +
  0x03, 0x00, 0xE0, 0x60, 0x00, 0x00, 0x00,  // Code for char ,
  0x05, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00,  // Code for char -
  0x03, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00,  // Code for char .
  0x04, 0xC0, 0x30, 0x0C, 0x03, 0x00, 0x00,  // Code for char /
  0x05, 0x7F, 0x51, 0x49, 0x45, 0x7F, 0x00,  // Code for char 0
  0x05, 0x42, 0x41, 0x7F, 0x40, 0x40, 0x00,  // Code for char 1
  0x05, 0x79, 0x49, 0x49, 0x49, 0x4F, 0x00,  // Code for char 2
  0x05, 0x41, 0x49, 0x49, 0x49, 0x7F, 0x00,  // Code for char 3
  0x05, 0x18, 0x14, 0x12, 0x7F, 0x10, 0x00,  // Code for char 4
  0x05, 0x4F, 0x49, 0x49, 0x49, 0x71, 0x00,  // Code for char 5
  0x05, 0x7C, 0x4A, 0x49, 0x49, 0x79, 0x00,  // Code for char 6
  0x05, 0x01, 0x01, 0x61, 0x19, 0x07, 0x00,  // Code for char 7
  0x05, 0x7F, 0x49, 0x49, 0x49, 0x7F, 0x00,  // Code for char 8
  0x05, 0x4F, 0x49, 0x49, 0x29, 0x1F, 0x00,  // Code for char 9
  0x03, 0x00, 0x6C, 0x6C, 0x00, 0x00, 0x00,  // Code for char :
  0x03, 0x00, 0xEC, 0x6C, 0x00, 0x00, 0x00,  // Code for char ;
  0x04, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00,  // Code for char <
  0x05, 0x24, 0x24, 0x24, 0x24, 0x24, 0x00,  // Code for char =
  0x05, 0x00, 0x41, 0x22, 0x14, 0x08, 0x00,  // Code for char >
  0x05, 0x03, 0x59, 0x59, 0x09, 0x0F, 0x00,  // Code for char ?
  0x05, 0x7F, 0x41, 0x5D, 0x55, 0x1F, 0x00,  // Code for char @
  0x05, 0x7F, 0x09, 0x09, 0x09, 0x7F, 0x00,  // Code for char A
  0x05, 0x7F, 0x49, 0x49, 0x49, 0x77, 0x00,  // Code for char B
  0x05, 0x7F, 0x41, 0x41, 0x41, 0x63, 0x00,  // Code for char C
  0x05, 0x7F, 0x41, 0x41, 0x41, 0x3E, 0x00,  // Code for char D
  0x05, 0x7F, 0x49, 0x49, 0x49, 0x41, 0x00,  // Code for char E
  0x05, 0x7F, 0x09, 0x09, 0x09, 0x01, 0x00,  // Code for char F
  0x05, 0x7F, 0x41, 0x41, 0x49, 0x79, 0x00,  // Code for char G
  0x05, 0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00,  // Code for char H
  0x03, 0x41, 0x7F, 0x41, 0x00, 0x00, 0x00,  // Code for char I
  0x03, 0x60, 0x40, 0x7F, 0x00, 0x00, 0x00,  // Code for char J
  0x04, 0x7F, 0x08, 0x14, 0x63, 0x00, 0x00,  // Code for char K
  0x04, 0x7F, 0x40, 0x40, 0x40, 0x00, 0x00,  // Code for char L
  0x05, 0x7E, 0x01, 0x3E, 0x01, 0x7E, 0x00,  // Code for char M
  0x05, 0x7F, 0x02, 0x04, 0x08, 0x7F, 0x00,  // Code for char N
  0x05, 0x7F, 0x41, 0x41, 0x41, 0x7F, 0x00,  // Code for char O
  0x05, 0x7F, 0x09, 0x09, 0x09, 0x0F, 0x00,  // Code for char P
  0x05, 0x7F, 0x41, 0x51, 0x61, 0xFF, 0x00,  // Code for char Q
  0x05, 0x7F, 0x09, 0x09, 0x19, 0x6F, 0x00,  // Code for char R
  0x05, 0x6F, 0x49, 0x49, 0x49, 0x7B, 0x00,  // Code for char S
  0x05, 0x01, 0x01, 0x7F, 0x01, 0x01, 0x00,  // Code for char T
  0x05, 0x7F, 0x40, 0x40, 0x40, 0x7F, 0x00,  // Code for char U
  0x05, 0x07, 0x18, 0x60, 0x18, 0x07, 0x00,  // Code for char V
  0x05, 0x3F, 0x40, 0x3E, 0x40, 0x3F, 0x00,  // Code for char W
  0x05, 0x63, 0x14, 0x08, 0x14, 0x63, 0x00,  // Code for char X
  0x05, 0x07, 0x08, 0x70, 0x08, 0x07, 0x00,  // Code for char Y
  0x05, 0x71, 0x49, 0x49, 0x49, 0x47, 0x00,  // Code for char Z
  0x03, 0x7F, 0x41, 0x41, 0x00, 0x00, 0x00,  // Code for char [
  0x04, 0x03, 0x0C, 0x30, 0xC0, 0x00, 0x00,  // Code for char BackSlash
  0x05, 0x00, 0x00, 0x41, 0x41, 0x7F, 0x00,  // Code for char ]
  0x05, 0x04, 0x02, 0x01, 0x02, 0x04, 0x00,  // Code for char ^
  0x06, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  // Code for char _
  0x03, 0x00, 0x03, 0x07, 0x00, 0x00, 0x00,  // Code for char `
  0x05, 0x74, 0x54, 0x54, 0x54, 0x7C, 0x00,  // Code for char a
  0x05, 0x7F, 0x44, 0x44, 0x44, 0x7C, 0x00,  // Code for char b
  0x05, 0x7C, 0x44, 0x44, 0x44, 0x44, 0x00,  // Code for char c
  0x05, 0x7C, 0x44, 0x44, 0x44, 0x7F, 0x00,  // Code for char d
  0x05, 0x7C, 0x54, 0x54, 0x54, 0x5C, 0x00,  // Code for char e
  0x05, 0x04, 0x7E, 0x05, 0x05, 0x01, 0x00,  // Code for char f
  0x05, 0xBC, 0xA4, 0xA4, 0xA4, 0xFC, 0x00,  // Code for char g
  0x05, 0x7F, 0x04, 0x04, 0x04, 0x7C, 0x00,  // Code for char h
  0x03, 0x44, 0x7D, 0x40, 0x00, 0x00, 0x00,  // Code for char i
  0x03, 0x80, 0x84, 0xFD, 0x00, 0x00, 0x00,  // Code for char j
  0x04, 0x7F, 0x08, 0x14, 0x62, 0x00, 0x00,  // Code for char k
  0x03, 0x41, 0x7F, 0x40, 0x00, 0x00, 0x00,  // Code for char l
  0x05, 0x7C, 0x04, 0x7C, 0x04, 0x78, 0x00,  // Code for char m
  0x05, 0x7C, 0x04, 0x04, 0x04, 0x7C, 0x00,  // Code for char n
  0x05, 0x7C, 0x44, 0x44, 0x44, 0x7C, 0x00,  // Code for char o
  0x05, 0xFC, 0x24, 0x24, 0x24, 0x3C, 0x00,  // Code for char p
  0x05, 0x3C, 0x24, 0x24, 0x24, 0xFC, 0x00,  // Code for char q
  0x03, 0x7C, 0x04, 0x04, 0x00, 0x00, 0x00,  // Code for char r
  0x05, 0x5C, 0x54, 0x54, 0x54, 0x74, 0x00,  // Code for char s
  0x03, 0x04, 0x7F, 0x44, 0x00, 0x00, 0x00,  // Code for char t
  0x05, 0x7C, 0x40, 0x40, 0x40, 0x7C, 0x00,  // Code for char u
  0x05, 0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00,  // Code for char v
  0x05, 0x3C, 0x40, 0x3C, 0x40, 0x3C, 0x00,  // Code for char w
  0x05, 0x6C, 0x10, 0x10, 0x10, 0x6C, 0x00,  // Code for char x
  0x04, 0x9C, 0xA0, 0x60, 0x3C, 0x00, 0x00,  // Code for char y
  0x05, 0x64, 0x54, 0x54, 0x54, 0x4C, 0x00,  // Code for char z
  0x04, 0x08, 0x3E, 0x41, 0x41, 0x00, 0x00,  // Code for char {
  0x02, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00,  // Code for char |
  0x05, 0x00, 0x41, 0x41, 0x3E, 0x08, 0x00,  // Code for char }
  0x04, 0x08, 0x04, 0x08, 0x04, 0x00, 0x00,  // Code for char ~
  0x03, 0x04, 0x0A, 0x04, 0x00, 0x00, 0x00   // Code for char 
};