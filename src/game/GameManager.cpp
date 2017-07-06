//
//  GameManager.cpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#include "GameManager.hpp"






GameManager::GameManager(){
//    gameWindow = new GameWindowBuffer();
//    dataWindow1 = new DataWindowBuffer();
//    dataWindow2 = new DataWindowBuffer();
//    player1 = new Player();
//    player2 = new Player();
//    stage = new Stage();
}

GameManager::~GameManager(){
    
}




void GameManager::updateInputStatus(Status st[2]){
    in1 = st[0];
    in2 = st[1];
}

void GameManager::updateGameLogic(){
    
    if(in1.sw) player1.jump();
    if(in2.sw) player2.jump();
    
    stage.moveLeft();
    
    checkCollision();
}



void GameManager::updateWindowBuffer(){
    
 
    
    
}


//helper
void GameManager::checkCollision(){

    int x1 = player1.posX;
    int y1 = player1.posY;
    int x2 = player2.posX;
    int y2 = player2.posY;
    
    if(stage.buffer[y1][x1]){
        player1.dead();
    }
    if(stage.buffer[y2][x2]){
        player2.dead();
    }
    
}



