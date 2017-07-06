//
//  WindowBuffer.cpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#include "WindowBuffer.hpp"





//original:: reffer to LEDMatrix::dispMat
void GameWindowBuffer::dispDebug(ofPoint ofpos, int matsz){
    
    //start
    ofPushMatrix();
    ofTranslate(ofpos.x, ofpos.y);
    
    //frame
    ofFill();
    ofSetColor(200);
    ofDrawRectangle(0,0,matsz,matsz);
    ofNoFill();
    ofSetColor(0);
    ofDrawRectangle(0,0,matsz,matsz);
    ofFill();
    
    //leds
    int LEDpitch = matsz/8;
    ofTranslate(LEDpitch/2, LEDpitch/2);
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            if( buffer[y][x]){
                ofSetColor(255,0,0 );
            }else{
                ofSetColor(255, 255, 255);
            }
            ofDrawCircle(LEDpitch*x, LEDpitch*y, LEDpitch*0.4);
        }
    }
    
    //end
    ofPopMatrix();
}




void DataWindowBuffer::setText(TextContent txt){
    for(int n=0;n<length;n++){
        unsigned char ch = txt.get(n);
        for(int y=0;y<8;y++){
            for(int x=0;x<8;x++){
                data[y][n*8+x] = fontbook[ch].data[y][x];
            }
        }
    }
}



void DataWindowBuffer::initFontBook(){
    //create font book
    for(unsigned char ch = 0;ch<128;ch++){
        fontbook[ch] =*new FontTo8x8(ch);
    }
}






//contents is cloned from GWB::dispDebug()
void DataWindowBuffer::dispDebug(ofPoint ofpos, int matsz){
    
    //start
    ofPushMatrix();
    ofTranslate(ofpos.x, ofpos.y);
    
    //frame
    ofFill();
    ofSetColor(200);
    ofDrawRectangle(0,0,matsz,matsz);
    ofNoFill();
    ofSetColor(0);
    ofDrawRectangle(0,0,matsz,matsz);
    ofFill();
    
    //leds
    int LEDpitch = matsz/8;
    ofTranslate(LEDpitch/2, LEDpitch/2);
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            if( buffer[y][x]){
                ofSetColor(255,0,0 );
            }else{
                ofSetColor(255, 255, 255);
            }
            ofDrawCircle(LEDpitch*x, LEDpitch*y, LEDpitch*0.4);
        }
    }
    
    //end
    ofPopMatrix();
}
