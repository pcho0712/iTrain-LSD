//
//  Stage.cpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#include "Stage.hpp"



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



void Stage::setRandomBuffer(){
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            buffer[y][x]= ofRandom(0,1)>0.7 ? 1:0;
        }
    }
}


