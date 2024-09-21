#ifndef _WORD_H_
#define _WORD_H_

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



#endif