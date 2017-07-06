//
//  WindowBuffer.hpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#ifndef WindowBuffer_hpp
#define WindowBuffer_hpp

#include <stdio.h>
#include <ofMain.h>
#include "TextContent.hpp"
#include "FontTo8x8.hpp"


class GameWindowBuffer{
public:
    unsigned char buffer[8][8*14];//14LED

    void setBuffer(unsigned char*);

    //debug-function
    void dispDebug(ofPoint,int);
};




class DataWindowBuffer{
    public:
    unsigned char buffer[8][8*4];//4LED
    FontTo8x8 fontbook[128];//font-book


    void setText(TextContent);//LSDに参考になる関数あり

    //utility-function
    void initFontBook();
    
    //debug-function
    void dispDebug(ofPoint,int);
};





#endif /* WindowBuffer_hpp */
