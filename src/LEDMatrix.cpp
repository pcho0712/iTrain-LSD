//
//  LEDMatrix.cpp
//  test-nishioka
//
//  Created by 吉田貴寿 on 2017/06/16.
//
//

#include "LEDMatrix.hpp"


LEDMatrix::LEDMatrix(){
    
}
LEDMatrix::~LEDMatrix(){
    
}


void LEDMatrix::setData(unsigned char array[8][8]){
    for(int y=0;y<8;y++){
        for(int x=0;x<8;x++){
            data[y][x]=array[y][x];
        }
    }
}

void LEDMatrix::setMatSize(int sz){
    matSize = sz;
}


void LEDMatrix::setRandomData(){
    for(int y=0;y<8;y++){
        for(int x=0;x<8;x++){
            data[y][x]= ofRandom(0,1)>0.5 ? 1:0;
        }
    }
    
    
}

void LEDMatrix::setDispPos(ofPoint ofp){
    dispPos = ofp;
}


unsigned char LEDMatrix::getLine(int iLine){
    unsigned char buf=0;
    
    buf += data[iLine][0] * 0x01;
    buf += data[iLine][1] * 0x02;
    buf += data[iLine][2] * 0x04;
    buf += data[iLine][3] * 0x08;
    buf += data[iLine][4] * 0x10;
    buf += data[iLine][5] * 0x20;
    buf += data[iLine][6] * 0x40;
    buf += data[iLine][7] * 0x80;

    return buf;
    
}




void LEDMatrix::dispMatrix(){
    dispMatrix(dispPos,matSize);
}

void LEDMatrix::dispMatrix(ofPoint ofpos,int matsz){
    
    ofPushMatrix();
    ofTranslate(ofpos.x, ofpos.y);
    
    ofFill();
    ofSetColor(200);
    ofDrawRectangle(0,0,matsz,matsz);
    ofNoFill();
    ofSetColor(0);
    ofDrawRectangle(0,0,matsz,matsz);
    ofFill();
    
    
    int LEDpitch = matsz/8;

    
    ofTranslate(LEDpitch/2, LEDpitch/2);
    
    for(int y=0;y<8;y++){
        for(int x=0;x<8;x++){
            if( data[y][x]){
                ofSetColor(255,0,0 );
            }else{
                ofSetColor(255, 255, 255);
            }
            
            ofDrawCircle(LEDpitch*x, LEDpitch*y, LEDpitch*0.4);
      
            
        }
    }
    
    ofPopMatrix();
    
}


