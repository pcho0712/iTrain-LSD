//
//  WindowBuffer.cpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#include "WindowBuffer.hpp"
#include <string>


void GameWindowBuffer::setStage(Stage stage)
{
	for (int y = 0; y < windowHeight; y++) {
		for (int x = 0; x < windowWidth; x++) {
			buffer[y][x] = stage.buffer[y][x];
		}
	}
}

void GameWindowBuffer::setPlayer(Player player1, Player player2) 
{
	buffer[player1.posY][player2.posX] = 1;
	buffer[player2.posY][player2.posX] = 1;
	if (player1.posY < windowHeight - 1) {
		buffer[player1.posY - 1][player1.posX] = 1;
	}
	if (player2.posY < windowHeight - 1) {
		buffer[player2.posY - 1][player2.posX] = 1;
	}
}


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
    for(int y=0;y<windowHeight;y++){
        for(int x=0;x<windowWidth;x++){
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


void DataWindowBuffer::setPlayer(Player player){
	int tmpt = player.time;
	if (tmpt > 1000) tmpt = 1000;

	text.set4dig(tmpt);


    for(int n=0;n<textLength;n++){
        unsigned char ch = text.get(n);
        for(int y=0;y<8;y++){
            for(int x=0;x<8;x++){
                buffer[y][n*8+x+offsetw] = fontbook[ch].data[y][x];
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
    for(int y=0;y<windowHeight;y++){
        for(int x=0;x<windowWidth;x++){
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
