//
//  FontTo8x8.hpp
//  test-nishioka
//
//  Created by 吉田貴寿 on 2017/06/16.
//
//

#ifndef FontTo8x8_hpp
#define FontTo8x8_hpp

#include <stdio.h>
#include "font8x8-master/font8x8_basic.h"

class FontTo8x8{
    
public:
    FONT8X8 f8;
    unsigned char ch;//unicode
    unsigned char data[8][8];//font
    
    FontTo8x8(unsigned char);
    FontTo8x8(unsigned wchar_t);

    FontTo8x8();

    ~FontTo8x8();
    
    void decodeFont(char);//ascii to font
    void decodeHiragana(unsigned wchar_t);
    
    
};


#endif /* FontTo8x8_hpp */
