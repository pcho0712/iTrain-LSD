//
//  LEDMatrix.hpp
//  test-nishioka
//
//  Created by 吉田貴寿 on 2017/06/16.
//
//

#ifndef LEDMatrix_hpp
#define LEDMatrix_hpp

#include <stdio.h>
#include <ofMain.h>


class LEDMatrix{
public:
    unsigned char data[8][8];
    ofPoint dispPos;
    int matSize = 200;
    
    LEDMatrix();
    ~LEDMatrix();
    
    void setData(unsigned char[8][8]);
    void setMatSize(int);
    void setRandomData();
    void setDispPos(ofPoint);
    
    unsigned char getLine(int);
    unsigned char getRow(int);
    unsigned char getColumn(int);

    
    void dispMatrix();
    void dispMatrix(ofPoint,int);
    
    
};

#endif /* LEDMatrix_hpp */


////disp-data-sample
//unsigned char ldata[8][8] = {
//    {1,1,1,1,0,0,0,0},
//    {1,1,0,0,1,1,0,0},
//    {1,1,1,1,0,0,0,0},
//    {1,1,1,1,0,0,1,1},
//    {0,0,1,1,0,0,0,0},
//    {1,1,1,1,0,0,0,0},
//    {1,1,1,1,0,1,1,0},
//    {1,1,1,1,0,0,0,1}
//};
