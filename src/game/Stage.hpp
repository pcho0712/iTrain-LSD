//
//  Stage.hpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#ifndef Stage_hpp
#define Stage_hpp

#include <stdio.h>


class Stage{
    const int width = 8*14;
    const int height = 8;

    unsigned char buffer[8][8*14];
    
    void update();
    
    void moveLeft();

    //debug
    void setRandamBuffer();
    
    
};

#endif /* Stage_hpp */
