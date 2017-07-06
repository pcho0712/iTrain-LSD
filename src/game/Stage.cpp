//
//  Stage.cpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#include "Stage.hpp"

Stage::Stage(){
//    setRandomBuffer();//debug
    setGround();
    setRandomWall(0.8);
}

void Stage::moveLeft(){
    unsigned char buf=0;
    for(int y=0;y<height;y++){
        buf = buffer[y][0];
        for(int x=0;x<width-1;x++){
            buffer[y][x]=buffer[y][x+1];
        }
        buffer[y][width-1] = buf;
    }
}



//util

void Stage::setGround(){
    
    for(int x=0;x<width;x++){
        buffer[7][x] = 1;
    }
}

void Stage::setWall(int x,int h){
    
    for(int y=0;y<h;y++){
        buffer[6-y][x] = 1;
    }
  
}

void Stage::setRandomWall(float wallRate){
    int maxHeight =5;
    for(int x=0;x<width;x++){
        if(ofRandom(0,1)>wallRate) {
            setWall(x,(int)ofRandom(0,maxHeight));
        }
    }
}




void Stage::setRandomBuffer(){
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            buffer[y][x]= ofRandom(0,1)>0.7 ? 1:0;
        }
    }
}


