//
//  Player.cpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#include "Player.hpp"






void Player::update(){
    time++;
    restrictPosition();
}


void Player::move(int x,int y){
    posX+=x;
    posY+=y;
    restrictPosition();
}

void Player::jump(){
 // modify here
}

void Player::dead(){
    time = 0;
}


//helper
void     restrictPosition(){
    if(posX < 0) posX = 0;
    if(posY < 0) posY = 0;
    if(posX > limX -1 ) posX = limX-1;
    if(posY > limY -1 ) posY = limY-1;
    
}
