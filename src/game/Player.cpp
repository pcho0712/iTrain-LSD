//
//  Player.cpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#include "Player.hpp"


Player::Player(){
    setPos(6,6);
}


void Player::update(){
    updateTime();
    if(isJump()) moveWhileJump(time-timeJumpStart);
    restrictPosition();
}


void Player::move(int x,int y){
    posX+=x;
    posY+=y;
    restrictPosition();
}

void Player::jump(){
    if(!isJump()) timeJumpStart = time;
}

void Player::dead(){
    if(!isJump()){
        time = 0;
        timeJumpStart = -10000;
    }
}


//helper
void Player::updateTime(){
    time++;
}

void Player::dispDebug(){
    string msg;
    
    //status
    msg += "time: "+ to_string(time) + ", ";
    msg += "timeJumpStart: "+ to_string(timeJumpStart) + ", ";
    msg += "isJump(): "+ to_string(isJump()) + "\n";
//    return msg;
//    cout << msg << endl;
    ofSetColor(0);
    ofDrawBitmapString(msg, 400, 50);
    
}



void Player::setPos(int x, int y){
    posX=x;
    posY=y;
    restrictPosition();
}

void  Player::restrictPosition(){
    if(posX < 0) posX = 0;
    if(posY < 0) posY = 0;
    if(posX > limX -1 ) posX = limX-1;
    if(posY > limY -1 ) posY = limY-1;
    
}


bool Player::isJump(){
    
    if (time - timeJumpStart < jumpDuration ) return true;
    else return false;
    
}

void Player::moveWhileJump(long count){
    if (count==2) move(0,-1);
    if (count==4) move(0,-1);
    if (count==8) move(0,-1);
    if (count==14) move(0,-1);
    if (count==20) move(0,1);
    if (count==24) move(0,1);
    if (count==26) move(0,1);
    if (count==28) move(0,1);
}
