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




class GameWindowBuffer{
    unsigned char buffer[8][8*14];//14LED

    void setBuffer(unsigned char*);

    //debug-function
    void dispDebug(ofPoint,int);
};



class DataWindowBuffer{
    unsigned char buffer[8][8*4];//4LED

    void setText(TextContent);//LSDに参考になる関数あり

    //debug-function
    void dispDebug(ofPoint,int);
};




//固定長配列でやることにします
/*
 class WindowBuffer{
 unsigned char buffer[][];
 
 void setText(TextContent);//LSDに参考になる関数あり
 void setBuffer(unsigned char[][]);
 
 //debug-function
 void dispDebug();
 
 };
 */

#endif /* WindowBuffer_hpp */
