//
//  GameManager.hpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include <ofMain.h>
#include "Status.hpp"
#include "Player.hpp"
#include "Stage.hpp"
#include "WindowBuffer.hpp"


class GameManager{
    
public:
    GameWindowBuffer gameWindow;
    DataWindowBuffer dataWindow1, dataWindow2;
    Player player1,player2;
    Stage stage;
    Status in1, in2;
    
    GameManager();
    ~GameManager();

    void updateInputStatus(Status[2]);
    void updateGameLogic();
    void updateWindowBuffer();
  
    
private:
    //internal updateInputStatus
    
    //internal updateGameLogic
    void checkCollision();

    //internal updateWindowBuffer

    
};









#endif /* GameManager_hpp */
