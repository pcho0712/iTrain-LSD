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
    player2.setPos(3,6);
//    stage = new Stage();
}

GameManager::~GameManager(){
    
}




void GameManager::updateInputStatus(Status st[2]){
    in1 = st[0];
    in2 = st[1];
}

void GameManager::updateGameLogic(){
    //player
    player1.update();
    player2.update();
    if(in1.sw) player1.jump();
    if(in2.sw) player2.jump();
    int rotateThreshold = 10;
    if(in1.pos >rotateThreshold) player1.move(1,0);
    if(in1.pos <-rotateThreshold) player1.move(-1,0);
    if(in2.pos >rotateThreshold) player2.move(1,0);
    if(in2.pos <-rotateThreshold) player2.move(-1,0);

    //stage
    if(ofGetFrameNum()%4==0) stage.moveLeft();

    //collision judge
    checkCollision();
}



void GameManager::updateWindowBuffer(){
	gameWindow.setStage(stage);
	gameWindow.setPlayer(player1, player2);
	dataWindow1.setPlayer(player1);
	dataWindow2.setPlayer(player2);
}

void GameManager::dispDebug(){
    gameWindow.dispDebug(ofPoint(330,500), 50);
    dataWindow1.dispDebug(ofPoint(330,550), 50);
    dataWindow2.dispDebug(ofPoint(330,600), 50);
    player1.dispDebug();
}



//helper
void GameManager::checkCollision(){
    if(stage.buffer[player1.posY][player1.posX]) player1.dead();
    if(stage.buffer[player2.posY][player2.posX]) player2.dead();
}



