#pragma once

#include "ofMain.h"
#include "LEDMatrix.hpp"
#include "LineDisplay.hpp"
#include "TwistedRingInterface.hpp"
#include "REDModule.hpp"
#include "FontTo8x8.hpp"
#include "font8x8-master/font8x8_basic.h"
//Game
#include "game/GameManager.hpp"



//debug condition
//#define DEBUG_TRI
//#define DEBUG_RED


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
//    LEDMatrix lmat;
    LineDisplay ldisp;
    FontTo8x8 font[128];//font-book
    REDModule red0,red1,red2;
    TwistedRingInterface tri;
    GameManager gm;
    
    Status debugStatus[2];
    

};
