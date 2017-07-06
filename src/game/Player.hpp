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
    long time;
    int posX,posY;
    
    void update();
    
    void move(int,int);
    void jump();
    void dead();
    
    
};


#endif /* Player_hpp */
