//
//  WindowBuffer.hpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#ifndef WindowBuffer_hpp
#define WindowBuffer_hpp

#include <stdio.h>
#include <ofMain.h>
#include "Stage.hpp"
#include "Player.hpp"




class GameWindowBuffer{
public:
	unsigned char buffer[8][8*14];//14LED
	
	int windowHeight = 8;
	int windowWidth = 8 * 14;

    void setStage(Stage stage);
	void setPlayer(Player player);

    //debug-function
    void dispDebug(ofPoint,int);
};



class DataWindowBuffer{
public:
    unsigned char buffer[8][8*4];//4LED
	int windowHeight = 8;
	int windowWidth = 8 * 40;

    void setPlayer(Player player1, Player player2);//LSDに参考になる関数あり

    //debug-function
    void dispDebug(ofPoint,int);
};




//固定長配列でやることにします
/*
 class WindowBuffer{
 unsigned char buffer[][];
 
 void setText(TextContent);//LSDに参考になる関数あり
 void setBuffer(unsigned char[][]);
 
 //debug-function
 void dispDebug();
 
 };
 */

#endif /* WindowBuffer_hpp */
