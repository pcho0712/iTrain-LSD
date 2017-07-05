//
//  FontTo8x8.cpp
//  test-nishioka
//
//  Created by 吉田貴寿 on 2017/06/16.
//
//

#include "FontTo8x8.hpp"



FontTo8x8::FontTo8x8(unsigned char ch){
        decodeFont(ch);
}
//FontTo8x8::FontTo8x8(unsigned wchar_t ch){
//    decodeHiragana(ch);
//}


FontTo8x8::FontTo8x8(){
}

FontTo8x8::~FontTo8x8(){
    
}



void FontTo8x8::decodeFont(char ch){
    unsigned char* font = f8.font8x8_basic[ch];
    //    { 0x0C, 0x1E, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x00},   // U+0041 (A)
    
    for(int y=0;y<8;y++){
        data[y][0] = (font[y] & 0x01) >> 0;//    0x0C & 0x00
        data[y][1] = (font[y] & 0x02) >> 1;//    0x0C & 0x00
        data[y][2] = (font[y] & 0x04) >> 2;//    0x0C & 0x00
        data[y][3] = (font[y] & 0x08) >> 3;//    0x0C & 0x00
        data[y][4] = (font[y] & 0x10) >> 4;//    0x0C & 0x00
        data[y][5] = (font[y] & 0x20) >> 5;//    0x0C & 0x00
        data[y][6] = (font[y] & 0x40) >> 6;//    0x0C & 0x00
        data[y][7] = (font[y] & 0x80) >> 7;//    0x0C & 0x00

    }
}
//
//void FontTo8x8::decodeHiragana(unsigned wchar_t ch){
//    int idx = ch - L'あ';
//    unsigned char* font = f8.font8x8_hiragana[ch];
//    //    { 0x0C, 0x1E, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x00},   // U+0041 (A)
//    
//    for(int y=0;y<8;y++){
//        data[y][0] = font[y] & 0x01;//    0x0C & 0x00
//        data[y][1] = font[y] & 0x02;//    0x0C & 0x00
//        data[y][2] = font[y] & 0x04;//    0x0C & 0x00
//        data[y][3] = font[y] & 0x08;//    0x0C & 0x00
//        data[y][4] = font[y] & 0x10;//    0x0C & 0x00
//        data[y][5] = font[y] & 0x20;//    0x0C & 0x00
//        data[y][6] = font[y] & 0x40;//    0x0C & 0x00
//        data[y][7] = font[y] & 0x80;//    0x0C & 0x00
//    }
//    
//    
//    
//}
