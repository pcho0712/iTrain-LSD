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
#include "TextContent.hpp"
#include "FontTo8x8.hpp"
#include "Stage.hpp"
#include "Player.hpp"


class GameWindowBuffer{
public:
	unsigned char buffer[8][8*14];//14LED
	
	int windowHeight = 8;
	int windowWidth = 8 * 14;

    void setStage(Stage stage);
	void setPlayer(Player player1, Player player2);

    //debug-function
    void dispDebug(ofPoint,int);
};




class DataWindowBuffer{
    public:
    unsigned char buffer[8][8*4];//4LED
    FontTo8x8 fontbook[128];//font-book
	TextContent text;

	const int textLength = 4;


	int windowHeight = 8;
	int windowWidth = 8 * 5;
	int offsetw = 8 / 2;

    void setPlayer(Player player);//LSDに参考になる関数あり

    //utility-function
    void initFontBook();
    
    //debug-function
    void dispDebug(ofPoint,int);
};





#endif /* WindowBuffer_hpp */
