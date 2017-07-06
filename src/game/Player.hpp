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


class Player{
public:
    long time;
    int posX,posY;
    const int limX=8, limY=8*14;
    
    void update();
    
    void move(int,int);
    void jump();
    void dead();
    
    
};


#endif /* Player_hpp */
