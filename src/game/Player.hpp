//
//  Player.hpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <ofMain.h>


class Player{
public:
    long time;
    int posX,posY;
    const int limX=8*14, limY=8;
    
    Player();
    
    void update();
    
    void move(int,int);
    void jump();
    void dead();
    
    //utility
    void restrictPosition();
    void setPos(int,int);
    void updateTime();
    void dispDebug();
    //jump
    long jumpDuration = 30;
    long timeJumpStart = -1000;
    bool isJump();
    void moveWhileJump(long);
    
    
    
};


#endif /* Player_hpp */
