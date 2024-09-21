#ifndef _WORD_H_
#define _WORD_H_

/*0-9数字字符，对应的点阵为：宽x高=6x11，不是8的倍数，扩展为8*11*/
char Number_size8[][11]{
0x00,0x78,0xFC,0xCC,0xCC,0xCC,0xCC,0xFC,0x78,0x00,0x00, //'0'
0x00,0x30,0x70,0x30,0x30,0x30,0x30,0x30,0x78,0x00,0x00, //'1'
0x00,0x78,0xDC,0xCC,0x18,0x38,0x70,0xCC,0xFC,0x00,0x00, //'2'
0x00,0x78,0xDC,0x1C,0x18,0x38,0x1C,0xCC,0xF8,0x00,0x00, //'3'
0x00,0x18,0x38,0x78,0x78,0xD8,0xFC,0x18,0x3C,0x00,0x00, //'4'
0x00,0x7C,0xC0,0xC0,0xF8,0x6C,0x0C,0xDC,0x78,0x00,0x00, //'5'
0x00,0x78,0xFC,0xC0,0xF8,0xEC,0xCC,0xEC,0x78,0x00,0x00, //'6'
0x00,0xFC,0xC8,0x18,0x10,0x30,0x30,0x70,0x70,0x00,0x00, //'7'
0x00,0x78,0xCC,0xCC,0x78,0xD8,0xCC,0xCC,0x78,0x00,0x00, //'8'
0x00,0x78,0xDC,0xCC,0xDC,0xFC,0x1C,0xF8,0x78,0x00,0x00, //'9'
0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00, //'-'
};

/*--0-9数字字符  宋体16;  此字体下对应的点阵为：宽x高=11x21 宽度不是8的倍数，现调整为：宽度x高度=16x20--*/
char Number_size16[][40]{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  /*--  文字:  -  --*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x00,0x3B,0x80,0x71,0xC0,0x71,0xC0,
0x71,0xC0,0xE1,0xE0,0xE0,0xE0,0xE0,0xE0,0xE1,0xE0,0x71,0xC0,0x71,0xC0,0x71,0xC0,
0x3B,0x80,0x1F,0x00,0x00,0x00,0x00,0x00,  /*--  文字:  0  --*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x3E,0x00,0x1E,0x00,0x0E,0x00,
0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,
0x0E,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,/*--  文字:  1  --*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x80,0x73,0xC0,0x61,0xC0,0x71,0xC0,
0x71,0xC0,0x01,0xC0,0x03,0x80,0x07,0x00,0x0E,0x00,0x1C,0x00,0x38,0x40,0x70,0xC0,
0x7F,0xC0,0xFF,0xC0,0x00,0x00,0x00,0x00,/*--  文字:  2  --*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x73,0x80,0x71,0xC0,0x71,0xC0,
0x01,0x80,0x07,0x80,0x0F,0x00,0x03,0x80,0x01,0xC0,0x01,0xC0,0x71,0xC0,0x71,0xC0,
0x73,0x80,0x3F,0x80,0x00,0x00,0x00,0x00,/*--  文字:  3  --*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x07,0x80,0x07,0x80,0x0F,0x80,
0x1F,0x80,0x3B,0x80,0x33,0x80,0x63,0x80,0xE3,0x80,0xFF,0xE0,0x03,0x80,0x03,0x80,
0x03,0x80,0x0F,0xE0,0x00,0x00,0x00,0x00,/*--  文字:  4  --*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xC0,0x3F,0x80,0x70,0x00,0x70,0x00,
0x60,0x00,0x7F,0x80,0x7B,0xC0,0x61,0xC0,0x01,0xC0,0x00,0xC0,0x71,0xC0,0x71,0xC0,
0x73,0x80,0x3F,0x80,0x00,0x00,0x00,0x00,/*--  文字:  5  --*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x3D,0xC0,0x71,0xC0,0x70,0x00,
0x70,0x00,0xFF,0x80,0xFB,0xC0,0xF1,0xC0,0xE0,0xE0,0xE0,0xE0,0x70,0xE0,0x71,0xC0,
0x3B,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,/*--  文字:  6  --*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xE0,0x7F,0xC0,0x61,0x80,0x41,0x80,
0x03,0x00,0x07,0x00,0x06,0x00,0x0E,0x00,0x0E,0x00,0x0C,0x00,0x1C,0x00,0x1C,0x00,
0x1C,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,/*--  文字:  7  --*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x80,0x7B,0xC0,0x61,0xC0,0x60,0xC0,
0x71,0xC0,0x79,0x80,0x1F,0x00,0x37,0x80,0x63,0xC0,0xE1,0xC0,0xE0,0xC0,0xE1,0xC0,
0x7B,0xC0,0x3F,0x80,0x00,0x00,0x00,0x00,/*--  文字:  8  --*/

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x7B,0x80,0x71,0xC0,0xE1,0xC0,
0xE1,0xC0,0xE1,0xE0,0xE1,0xE0,0x7B,0xC0,0x3F,0xC0,0x01,0xC0,0x01,0xC0,0x73,0x80,
0x77,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,/*--  文字:  9  --*/
};

/*--  文字:  游  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=48x48   --*/
char word[48*48/8]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xC0,0x00,0x07,0x00,0xC0,0x01,0xF0,0x00,0x03,0xC0,0xF0,0x01,0xF8,0x00,0x03,0xE0,
0x78,0x01,0xE0,0x00,0x01,0xF0,0x7C,0x03,0xE0,0x00,0x00,0xF8,0x3E,0x03,0xC0,0x00,
0x00,0xF8,0x3E,0x03,0x80,0x20,0x00,0x70,0x1E,0x07,0x80,0x70,0x00,0x70,0x1C,0x07,
0xFF,0xF8,0x00,0x04,0x01,0xC7,0xFF,0xFC,0x00,0x0F,0xFF,0xEE,0x00,0x00,0x70,0x0F,
0xFF,0xFE,0x00,0x00,0x38,0x0D,0xF8,0x1C,0x00,0x00,0x3E,0x1C,0x78,0x18,0x00,0xE0,
0x1F,0x1C,0x78,0x37,0xFF,0xF0,0x0F,0x98,0x78,0x77,0xFF,0xF8,0x0F,0xB8,0x70,0x03,
0x81,0xF8,0x0F,0xB8,0xF0,0xE0,0x03,0xC0,0x07,0xB8,0xFF,0xF0,0x07,0x80,0x07,0x30,
0xFF,0xF0,0x0E,0x00,0x00,0x70,0xF1,0xE0,0x3C,0x00,0x00,0x70,0xF1,0xE0,0x3E,0x00,
0x00,0x70,0xF1,0xE0,0x3C,0x00,0x00,0xE0,0xF1,0xE0,0x3C,0x00,0x00,0xE0,0xF1,0xE0,
0x3C,0x70,0x00,0xE0,0xF1,0xFF,0xFF,0xF8,0x01,0xE1,0xE1,0xFF,0xFF,0xFC,0x01,0xC1,
0xE1,0xEE,0x3C,0x00,0x7F,0xC1,0xE1,0xE0,0x3C,0x00,0x3F,0xC1,0xE1,0xE0,0x3C,0x00,
0x0F,0xC1,0xC1,0xC0,0x3C,0x00,0x07,0xC3,0xC1,0xC0,0x3C,0x00,0x07,0x83,0xC1,0xC0,
0x3C,0x00,0x07,0x87,0x83,0xC0,0x3C,0x00,0x07,0x87,0x83,0xC0,0x3C,0x00,0x07,0x87,
0x03,0xC0,0x3C,0x00,0x0F,0x8F,0x03,0xC0,0x3C,0x00,0x0F,0x8E,0x03,0xC0,0x3C,0x00,
0x0F,0x9D,0xE7,0x80,0x3C,0x00,0x07,0xBC,0xFF,0x87,0xFC,0x00,0x03,0xB8,0x3F,0x07,
0xFC,0x00,0x00,0x70,0x1F,0x00,0xFC,0x00,0x00,0xE0,0x1C,0x00,0x78,0x00,0x01,0xC0,
0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*--  文字:  戏  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=48x48   --*/
char word1[48*48/8]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,
0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,
0x00,0xF9,0xC0,0x00,0x00,0x00,0x00,0xF8,0xF8,0x00,0x00,0x00,0x00,0x78,0x7E,0x00,
0x00,0x00,0x00,0x78,0x3F,0x00,0x00,0x00,0x40,0x78,0x1F,0x80,0x00,0x00,0xE0,0x78,
0x1F,0x80,0x1F,0xFF,0xF8,0x78,0x0F,0x80,0x1F,0xFF,0xF8,0x78,0x07,0x80,0x0E,0x01,
0xF0,0x7C,0x03,0x60,0x00,0x01,0xF0,0x7C,0x00,0xF0,0x00,0x01,0xE0,0x7C,0x01,0xF8,
0x00,0x01,0xE0,0x3D,0xFF,0xFC,0x00,0x03,0xE3,0xFF,0xFF,0x00,0x0C,0x03,0xFF,0xFE,
0x00,0x00,0x0E,0x03,0xDC,0x3C,0x00,0x00,0x07,0x03,0xC0,0x3C,0x03,0x80,0x03,0xC7,
0xC0,0x3E,0x03,0xC0,0x01,0xE7,0x80,0x1E,0x07,0xE0,0x00,0xF7,0x80,0x1E,0x0F,0xE0,
0x00,0x7F,0x80,0x1E,0x0F,0x80,0x00,0x7F,0x00,0x1E,0x1F,0x00,0x00,0x3F,0x00,0x1F,
0x1F,0x00,0x00,0x1F,0x00,0x0F,0x3E,0x00,0x00,0x1F,0x00,0x0F,0x7C,0x00,0x00,0x3F,
0x80,0x0F,0xF8,0x00,0x00,0x3F,0xC0,0x0F,0xF0,0x00,0x00,0x7B,0xE0,0x07,0xF0,0x00,
0x00,0x7B,0xF0,0x07,0xE0,0x18,0x00,0xF1,0xF0,0x07,0xC0,0x18,0x00,0xE0,0xF8,0x0F,
0xE0,0x18,0x01,0xE0,0xF8,0x1F,0xE0,0x38,0x03,0xC0,0x78,0x3F,0xF0,0x38,0x03,0x80,
0x70,0xF8,0xF8,0x38,0x07,0x80,0x31,0xF0,0x7C,0x38,0x0F,0x00,0x03,0xE0,0x3F,0x78,
0x0E,0x00,0x07,0x80,0x3F,0xF8,0x1C,0x00,0x1F,0x00,0x1F,0xF8,0x38,0x00,0x3C,0x00,
0x0F,0xF8,0x70,0x00,0xF0,0x00,0x03,0xF8,0x60,0x01,0xC0,0x00,0x01,0xFC,0x00,0x00,
0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*--  文字:  结  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=48x48   --*/
char word2[48*48/8]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,
0x00,0x00,0x00,0x1C,0x00,0x03,0xC0,0x00,0x00,0x3F,0x00,0x03,0xE0,0x00,0x00,0x3F,
0x00,0x03,0xC0,0x00,0x00,0x3C,0x00,0x03,0xC0,0x00,0x00,0x7C,0x00,0x03,0xC0,0x00,
0x00,0x78,0x00,0x03,0xC0,0x00,0x00,0x78,0x00,0x03,0xC0,0x00,0x00,0xF0,0x00,0x03,
0xC0,0xF0,0x00,0xE0,0x1F,0xFF,0xFF,0xF8,0x01,0xE0,0x5F,0xFF,0xFF,0xFC,0x01,0xC0,
0xEF,0x03,0xC0,0x00,0x03,0xC1,0xF8,0x03,0xC0,0x00,0x03,0x81,0xF8,0x03,0xC0,0x00,
0x07,0x83,0xE0,0x03,0xC0,0x00,0x07,0x03,0xC0,0x03,0xC0,0x00,0x0E,0x07,0xC0,0x03,
0xC0,0x00,0x3F,0xFF,0x80,0x03,0xC1,0x80,0x1F,0xFF,0x00,0x03,0xC3,0xC0,0x1F,0xDE,
0x07,0xFF,0xFF,0xE0,0x0E,0x1E,0x07,0xFF,0xFF,0xF0,0x00,0x3C,0x03,0x80,0x00,0x00,
0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,
0x00,0x00,0x01,0xC0,0x03,0x00,0x01,0x80,0x03,0xC1,0xFB,0xFF,0xFF,0xC0,0x07,0xFF,
0xE3,0xFF,0xFF,0xE0,0x1F,0xFF,0x03,0xC0,0x03,0xE0,0x0F,0xF0,0x03,0xC0,0x03,0xC0,
0x0F,0xC0,0x03,0xC0,0x03,0xC0,0x07,0x00,0x03,0xC0,0x03,0xC0,0x00,0x00,0x03,0xC0,
0x03,0xC0,0x00,0x00,0x0B,0xC0,0x03,0xC0,0x00,0x00,0xFB,0xC0,0x03,0xC0,0x00,0x0F,
0xE3,0xC0,0x03,0xC0,0x00,0xFF,0x83,0xC0,0x03,0xC0,0x1F,0xFC,0x03,0xC0,0x03,0xC0,
0x1F,0xF0,0x03,0xFF,0xFF,0xC0,0x1F,0xC0,0x03,0xFF,0xFF,0xC0,0x0E,0x00,0x03,0xC0,
0x03,0xC0,0x0C,0x00,0x03,0xC0,0x03,0xC0,0x00,0x00,0x03,0xC0,0x03,0xC0,0x00,0x00,
0x03,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*--  文字:  束  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=48x48   --*/
char word3[48*48/8]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x80,0x00,0x00,0x00,0x00,0x07,0xE0,
0x00,0x00,0x00,0x00,0x07,0xE0,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x00,
0x03,0xC0,0x00,0x60,0x00,0x00,0x03,0xC0,0x00,0xF0,0x1F,0xFF,0xFF,0xFF,0xFF,0xF8,
0x1F,0xFF,0xFF,0xFF,0xFF,0xFC,0x0E,0x00,0x03,0xC0,0x00,0x00,0x00,0x00,0x03,0xC0,
0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0xE0,
0x03,0xC0,0x1E,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,
0x00,0xF8,0x03,0xC0,0x1E,0x00,0x00,0xF8,0x03,0xC0,0x1E,0x00,0x00,0xF8,0x03,0xC0,
0x1E,0x00,0x00,0xF8,0x03,0xC0,0x1E,0x00,0x00,0xF8,0x03,0xC0,0x1E,0x00,0x00,0xF8,
0x03,0xC0,0x1E,0x00,0x00,0xF8,0x03,0xC0,0x1E,0x00,0x00,0xF8,0x03,0xC0,0x1E,0x00,
0x00,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0xFF,0xFF,0xFF,0xFE,0x00,0x00,0xF8,0x1F,0xF0,
0x1E,0x00,0x00,0xF8,0x3F,0xF8,0x1E,0x00,0x00,0xF8,0x7F,0xF8,0x18,0x00,0x00,0xE0,
0x7F,0xDC,0x00,0x00,0x00,0x00,0xFB,0xDE,0x00,0x00,0x00,0x01,0xFB,0xCE,0x00,0x00,
0x00,0x01,0xF3,0xC7,0x00,0x00,0x00,0x03,0xE3,0xC7,0x80,0x00,0x00,0x07,0xC3,0xC3,
0xE0,0x00,0x00,0x0F,0x83,0xC1,0xF0,0x00,0x00,0x1F,0x03,0xC0,0xFC,0x00,0x00,0x3E,
0x03,0xC0,0x7E,0x00,0x00,0x7C,0x03,0xC0,0x3F,0xC0,0x00,0xF8,0x07,0xC0,0x1F,0xF8,
0x03,0xE0,0x07,0xC0,0x0F,0xFC,0x07,0xC0,0x07,0xC0,0x07,0xF0,0x1F,0x00,0x07,0xC0,
0x01,0xC0,0x3C,0x00,0x07,0xC0,0x00,0x00,0x30,0x00,0x07,0xC0,0x00,0x00,0x00,0x00,
0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*--  文字:  楚  --*/
/*--  宋体28;  此字体下对应的点阵为：宽x高=37x37   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=40x37  --*/
char word4[40*37/8]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x01,0xC0,0x00,0x00,
0x3E,0x01,0xF0,0x00,0x00,0x3C,0x01,0xE0,0x00,0x00,0x3C,0x01,0xE0,0x00,0x00,0x3C,
0x01,0xE0,0x00,0x00,0x3D,0xC1,0xE3,0x80,0x1F,0xFF,0xFF,0xFF,0xC0,0x0C,0x3C,0x0B,
0xE0,0x00,0x00,0x7C,0x03,0xE0,0x00,0x00,0x7F,0x87,0xF8,0x00,0x00,0xFF,0xCF,0xFE,
0x00,0x01,0xFD,0xCF,0xFF,0x00,0x01,0xFD,0xDD,0xEF,0x80,0x03,0xBC,0xF9,0xE7,0x80,
0x07,0x3C,0x71,0xE3,0x80,0x0E,0x3C,0xE1,0xE0,0x00,0x1C,0x3D,0xC1,0xE0,0x00,0x38,
0x38,0x01,0xC7,0x00,0x0F,0xFF,0xFF,0xFF,0x80,0x06,0x00,0x38,0x0F,0xC0,0x00,0x00,
0x38,0x1E,0x00,0x00,0x38,0x38,0x18,0x00,0x00,0x3C,0x38,0x0C,0x00,0x00,0x78,0x38,
0x1E,0x00,0x00,0x78,0x3F,0xFF,0x00,0x00,0xF0,0x38,0x00,0x00,0x00,0xF8,0x38,0x00,
0x00,0x01,0xEC,0x38,0x00,0x00,0x03,0xCF,0x38,0x00,0x00,0x03,0x83,0xF8,0x00,0x00,
0x07,0x01,0xFF,0xFF,0xF0,0x0E,0x00,0x7F,0xFF,0xE0,0x1C,0x00,0x0F,0xFF,0xC0,0x38,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*--  文字:  河  --*/
/*--  宋体28;  此字体下对应的点阵为：宽x高=37x37   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=40x37  --*/
char word5[40*37/8]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,
0x00,0x00,0x00,0xC0,0x0F,0x00,0x00,0x01,0xE0,0x07,0x9F,0xFF,0xFF,0xE0,0x03,0xCC,
0x00,0x0E,0x00,0x03,0xC0,0x00,0x0E,0x00,0x01,0xD0,0x00,0x0E,0x00,0x40,0x30,0x00,
0x0E,0x00,0x70,0x30,0x00,0x0E,0x00,0x38,0x30,0x00,0x0E,0x00,0x3C,0x77,0x07,0x0E,
0x00,0x1E,0x67,0xFF,0x8E,0x00,0x1E,0x67,0x87,0x0E,0x00,0x0C,0xE7,0x87,0x0E,0x00,
0x00,0xC7,0x87,0x0E,0x00,0x01,0xC7,0x87,0x0E,0x00,0x01,0xC7,0x87,0x0E,0x00,0x01,
0xC7,0x87,0x0E,0x00,0x03,0x87,0x87,0x0E,0x00,0x03,0x87,0x87,0x0E,0x00,0x03,0x87,
0xFF,0x0E,0x00,0x07,0x07,0x87,0x0E,0x00,0x7F,0x07,0x87,0x0E,0x00,0x1F,0x07,0x86,
0x0E,0x00,0x0F,0x06,0x00,0x0E,0x00,0x0F,0x00,0x00,0x0E,0x00,0x0F,0x00,0x00,0x0E,
0x00,0x0F,0x00,0x00,0x0E,0x00,0x0F,0x00,0x00,0x0E,0x00,0x1F,0x00,0x03,0xFE,0x00,
0x1F,0x00,0x00,0xFE,0x00,0x0F,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*--  文字:  汉  --*/
/*--  宋体28;  此字体下对应的点阵为：宽x高=37x37   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=40x37  --*/
char word6[40*37/8]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,
0x00,0x00,0x0C,0x00,0x07,0x80,0x00,0x0E,0x00,0x03,0xCF,0xFF,0xFF,0x00,0x01,0xE3,
0xC0,0x1E,0x00,0x01,0xE0,0xC0,0x1E,0x00,0x01,0xEC,0xC0,0x1C,0x00,0x00,0xCC,0xC0,
0x3C,0x00,0x60,0x1C,0xE0,0x3C,0x00,0x78,0x18,0xE0,0x3C,0x00,0x3C,0x18,0xE0,0x38,
0x00,0x1E,0x38,0x60,0x78,0x00,0x1F,0x30,0x70,0x78,0x00,0x0F,0x70,0x70,0x70,0x00,
0x0E,0x70,0x70,0xF0,0x00,0x06,0xE0,0x38,0xF0,0x00,0x00,0xE0,0x39,0xE0,0x00,0x00,
0xC0,0x3D,0xE0,0x00,0x01,0xC0,0x1F,0xC0,0x00,0x01,0xC0,0x1F,0xC0,0x00,0x03,0x80,
0x0F,0x80,0x00,0x03,0x80,0x0F,0x80,0x00,0x7F,0x80,0x0F,0x00,0x00,0x3F,0x00,0x1F,
0x80,0x00,0x0F,0x00,0x3F,0xC0,0x00,0x07,0x00,0x7D,0xF0,0x00,0x07,0x00,0xF8,0xF8,
0x00,0x0F,0x01,0xF0,0x7C,0x00,0x0F,0x03,0xC0,0x3F,0x00,0x0F,0x07,0x80,0x1F,0xE0,
0x0F,0x1E,0x00,0x0F,0xF0,0x0F,0x7C,0x00,0x03,0x80,0x01,0xE0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*--  文字:  界  --*/
/*--  宋体28;  此字体下对应的点阵为：宽x高=37x37   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=40x37  --*/
char word7[40*37/8]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0xC0,0x00,0x1C,0x00,0x01,0xFF,0xFF,0xFE,0x00,0x01,0xE0,0x70,0x1E,0x00,0x01,0xE0,
0x70,0x1C,0x00,0x01,0xE0,0x70,0x1C,0x00,0x01,0xE0,0x70,0x1C,0x00,0x01,0xFF,0xFF,
0xFC,0x00,0x01,0xE0,0x70,0x1C,0x00,0x01,0xE0,0x70,0x1C,0x00,0x01,0xE0,0x70,0x1C,
0x00,0x01,0xE0,0x70,0x1C,0x00,0x01,0xFF,0xFF,0xFC,0x00,0x01,0xE1,0xEE,0x1C,0x00,
0x01,0xC3,0xC7,0x10,0x00,0x00,0x07,0x83,0x80,0x00,0x00,0x0F,0x01,0xC0,0x00,0x00,
0x1E,0x01,0xF0,0x00,0x00,0x3F,0x03,0xFC,0x00,0x00,0x7F,0xC3,0xFF,0xE0,0x01,0xF7,
0x83,0xDF,0xF0,0x07,0xC7,0x03,0xC7,0xC0,0x1F,0x07,0x03,0xC0,0x80,0x38,0x0F,0x03,
0xC0,0x00,0x00,0x0F,0x03,0xC0,0x00,0x00,0x0E,0x03,0xC0,0x00,0x00,0x1E,0x03,0xC0,
0x00,0x00,0x1C,0x03,0xC0,0x00,0x00,0x3C,0x03,0xC0,0x00,0x00,0xF8,0x03,0xC0,0x00,
0x01,0xE0,0x03,0xC0,0x00,0x07,0x80,0x03,0xC0,0x00,0x1E,0x00,0x03,0x80,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*--  文字:  红  --*/
/*--  宋体28;  此字体下对应的点阵为：宽x高=37x37   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=40x37  --*/
char word8[40*37/8]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x00,
0x78,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0xF0,0x00,0x03,0x00,0x01,0xE0,
0x00,0x07,0x80,0x01,0xE1,0xFF,0xFF,0xC0,0x03,0xC0,0xC3,0xC0,0x00,0x03,0x87,0x03,
0xC0,0x00,0x07,0x07,0x83,0xC0,0x00,0x07,0x0F,0x83,0xC0,0x00,0x0E,0x0F,0x03,0xC0,
0x00,0x1C,0x1E,0x03,0xC0,0x00,0x3F,0xFC,0x03,0xC0,0x00,0x3F,0xF8,0x03,0xC0,0x00,
0x1C,0x78,0x03,0xC0,0x00,0x00,0xF0,0x03,0xC0,0x00,0x00,0xE0,0x03,0xC0,0x00,0x01,
0xC0,0x03,0xC0,0x00,0x03,0x80,0x03,0xC0,0x00,0x07,0x0F,0x83,0xC0,0x00,0x0F,0xFE,
0x03,0xC0,0x00,0x1F,0xE0,0x03,0xC0,0x00,0x1F,0x00,0x03,0xC0,0x00,0x0E,0x00,0x03,
0xC0,0x00,0x00,0x00,0xC3,0xC0,0x00,0x00,0x07,0xC3,0xC0,0x00,0x00,0x7E,0x03,0xC0,
0x00,0x03,0xF8,0x03,0xC1,0xC0,0x3F,0xC0,0x03,0xC3,0xE0,0x1F,0x0F,0xFF,0xFF,0xF0,
0x0C,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*--  文字:  黑  --*/
/*--  宋体28;  此字体下对应的点阵为：宽x高=37x37   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=40x37  --*/
char word9[40*37/8]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,
0x80,0x00,0x0E,0x00,0x03,0xFF,0xFF,0xFF,0x00,0x03,0xC0,0x70,0x0F,0x00,0x03,0xF0,
0x71,0xCE,0x00,0x03,0xFC,0x71,0xEE,0x00,0x03,0xDE,0x71,0xFE,0x00,0x03,0xCE,0x73,
0xCE,0x00,0x03,0xCF,0x73,0x8E,0x00,0x03,0xCF,0x77,0x0E,0x00,0x03,0xCF,0x77,0x0E,
0x00,0x03,0xC6,0x7E,0x0E,0x00,0x03,0xC0,0x7C,0x0E,0x00,0x03,0xFF,0xFF,0xFE,0x00,
0x03,0xC0,0x70,0x0E,0x00,0x03,0x80,0x70,0x00,0x00,0x00,0x00,0x70,0x0C,0x00,0x00,
0x00,0x70,0x1E,0x00,0x07,0xFF,0xFF,0xFF,0x00,0x03,0x00,0x70,0x00,0x00,0x00,0x00,
0x70,0x00,0x00,0x00,0x00,0x70,0x03,0x80,0x00,0x00,0x70,0x07,0xC0,0x3F,0xFF,0xFF,
0xFF,0xE0,0x1C,0x00,0x00,0x00,0x00,0x01,0xCC,0x18,0x38,0x00,0x01,0xCE,0x0E,0x1C,
0x00,0x01,0xC7,0x0F,0x0F,0x00,0x03,0x87,0x87,0x0F,0x80,0x03,0x87,0x87,0x87,0x80,
0x07,0x87,0x87,0x83,0xC0,0x0F,0x83,0x87,0x83,0x80,0x0F,0x03,0x03,0x03,0x80,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*--  文字:  方  --*/
/*--  宋体28;  此字体下对应的点阵为：宽x高=37x37   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=40x37  --*/
char word10[40*37/8]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,
0x01,0xF0,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,
0x78,0x00,0x00,0x00,0x00,0x38,0x01,0xC0,0x00,0x00,0x00,0x03,0xE0,0x7F,0xFF,0xFF,
0xFF,0xF0,0x38,0x01,0xE0,0x00,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x01,0xC0,0x00,
0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x03,0xC0,0x3C,0x00,
0x00,0x03,0xFF,0xFE,0x00,0x00,0x03,0xC0,0x3C,0x00,0x00,0x03,0x80,0x38,0x00,0x00,
0x03,0x80,0x38,0x00,0x00,0x07,0x80,0x78,0x00,0x00,0x07,0x00,0x78,0x00,0x00,0x0F,
0x00,0x78,0x00,0x00,0x0F,0x00,0x78,0x00,0x00,0x0E,0x00,0x78,0x00,0x00,0x1C,0x00,
0x70,0x00,0x00,0x3C,0x00,0x70,0x00,0x00,0x38,0x00,0xF0,0x00,0x00,0x70,0x00,0xF0,
0x00,0x00,0xE0,0x00,0xF0,0x00,0x01,0xC0,0xE0,0xF0,0x00,0x03,0x80,0x7F,0xE0,0x00,
0x0F,0x00,0x1F,0xE0,0x00,0x1C,0x00,0x0F,0xC0,0x00,0x38,0x00,0x07,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*--  文字:  和  --*/
/*--  宋体28;  此字体下对应的点阵为：宽x高=37x37   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=40x37  --*/
char word11[40*37/8]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0xC0,0x00,0x00,0x00,0x07,0xE0,0x00,0x00,0x00,0x7F,0xF0,0x00,0x00,0x0F,0xFE,
0x00,0x00,0x00,0x1F,0x3C,0x06,0x03,0xC0,0x00,0x3C,0x07,0xFF,0xE0,0x00,0x3C,0x07,
0x03,0xC0,0x00,0x3C,0x07,0x03,0xC0,0x00,0x3C,0x67,0x03,0xC0,0x00,0x3C,0xF7,0x03,
0xC0,0x3F,0xFF,0xFF,0x03,0xC0,0x08,0x7C,0x07,0x03,0xC0,0x00,0x7C,0x07,0x03,0xC0,
0x00,0x7C,0x07,0x03,0xC0,0x00,0xFF,0x07,0x03,0xC0,0x00,0xFF,0xC7,0x03,0xC0,0x01,
0xFF,0xE7,0x03,0xC0,0x01,0xFD,0xF7,0x03,0xC0,0x03,0xBC,0xF7,0x03,0xC0,0x07,0xBC,
0x77,0x03,0xC0,0x07,0x3C,0x07,0x03,0xC0,0x0E,0x3C,0x07,0x03,0xC0,0x1C,0x3C,0x07,
0x03,0xC0,0x38,0x3C,0x07,0xFF,0xC0,0x30,0x3C,0x07,0x03,0xC0,0x60,0x3C,0x07,0x03,
0xC0,0x00,0x3C,0x07,0x03,0x80,0x00,0x3C,0x07,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,
0x00,0x3C,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/*--  文字:  棋  --*/
/*--  宋体28;  此字体下对应的点阵为：宽x高=37x37   --*/
/*--  宽度不是8的倍数，现调整为：宽度x高度=40x37  --*/
char word12[40*37/8]={
0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0x60,0x30,0x00,0x01,0xF0,0x78,0x3C,0x00,0x01,
0xE0,0x7C,0x3E,0x00,0x01,0xE0,0x78,0x3C,0x00,0x01,0xE0,0x78,0x3C,0x00,0x01,0xE0,
0x78,0x3D,0x80,0x01,0xE0,0x78,0x3F,0xC0,0x01,0xE7,0xFF,0xFF,0xE0,0x01,0xEF,0x78,
0x3C,0x00,0x7F,0xFF,0x78,0x3C,0x00,0x31,0xE0,0x78,0x3C,0x00,0x01,0xE0,0x78,0x3C,
0x00,0x01,0xE0,0x7F,0xFC,0x00,0x03,0xE0,0x78,0x3C,0x00,0x03,0xF8,0x78,0x3C,0x00,
0x03,0xFC,0x78,0x3C,0x00,0x07,0xFE,0x78,0x3C,0x00,0x07,0xFE,0x78,0x3C,0x00,0x07,
0xEE,0x7F,0xFC,0x00,0x0F,0xEE,0x78,0x3C,0x00,0x0F,0xE0,0x78,0x3C,0x00,0x0F,0xE0,
0x78,0x3C,0xC0,0x1D,0xE0,0x78,0x3D,0xE0,0x19,0xEF,0xFF,0xFF,0xF0,0x39,0xE6,0x00,
0x00,0x00,0x31,0xE0,0x18,0x70,0x00,0x21,0xE0,0x3C,0x38,0x00,0x01,0xE0,0x7E,0x1E,
0x00,0x01,0xE0,0x78,0x0F,0x00,0x01,0xE0,0xF0,0x07,0x80,0x01,0xE1,0xE0,0x07,0xC0,
0x01,0xE3,0x80,0x03,0xE0,0x01,0xE7,0x00,0x01,0xE0,0x01,0xEE,0x00,0x01,0xC0,0x01,
0xD8,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00};

#endif