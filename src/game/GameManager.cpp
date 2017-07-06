//
//  GameManager.cpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#include "GameManager.hpp"



GameManager::GameManager(){
    gameWindow = new GameWindowBuffer();
    
}



void GameManager::updateInputStatus(Status[2] st){
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
void checkCollision(){

    int x1 = player1.posX;
    int y1 = player1.posY;
    int x2 = player2.posX;
    int y2 = player2.posY;
    
    if(Stage[y1][x1]){
        player1.dead();
    }
    if(Stage[y2][x2]){
        player2.dead();
    }
    
}



