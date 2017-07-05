//
//  LineDisplay.hpp
//  test-nishioka
//
//  Created by 吉田貴寿 on 2017/06/16.
//
//

#ifndef LineDisplay_hpp
#define LineDisplay_hpp

#include <stdio.h>
#include <ofMain.h>
#include "LEDMatrix.hpp"
#include "FontTo8x8.hpp"




class TextContent{
public:
    string text;
    unsigned char length;
    //    unsigned char* text;
    //    unsigned char length;
    
    TextContent();
    TextContent(string);
    ~TextContent();
    
    //    void setLength(unsigned char);
    void setText(string);
    string getText();
    unsigned char get(int);
    
};



class LineDisplay{

    public:
    const static int length=24;
    unsigned char data[8][8*length];//これを操作して毎フレームlmatsに割り付ける
    const int dispWidth = 8*length;
    const int dispHeight = 8;
    
    FontTo8x8 fontbook[128];//font-book
    TextContent text;
    
    int matSize=40;
    vector<LEDMatrix*> lmats;
    ofPoint dispPos;
   
    LineDisplay();
    ~LineDisplay();


    void uploadData();//ldisp.data to lmat.data
    void display(ofPoint);

    void setRandomData();
    void setText(TextContent);
    void initFontBook();
    
    //data operation
    void moveDataToRight01();
    void moveDataToLeft01();
    void addDataAtLast(unsigned char[8][8]);

};




#endif /* LineDisplay_hpp */
