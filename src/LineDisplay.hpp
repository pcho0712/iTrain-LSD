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
#include "TextContent.hpp"
#include "LEDMatrix.hpp"
#include "FontTo8x8.hpp"





class LineDisplay{

    public:
    const static int length=24;
    unsigned char data[8][8*length];//これを操作して毎フレームlmatsに割り付ける
    const int dispWidth = 8*length;
    const int dispHeight = 8;
	
	const int datawinWidth = 40;
	const int gamewinWidth = dispWidth - datawinWidth*2;
    
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
	void renderData(char datawin1[8][40], char datawin2[8][40], char gamewin[8][112]);
    
    //data operation
    void moveDataToRight01();
    void moveDataToLeft01();
    void addDataAtLast(unsigned char[8][8]);

};




#endif /* LineDisplay_hpp */
