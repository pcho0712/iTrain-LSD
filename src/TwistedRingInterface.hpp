//
//  TwistedRingInterface.hpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/06/18.
//
// inspired by http://qiita.com/shu223/items/a3754f8015875c1cc4f2

#ifndef TwistedRingInterface_hpp
#define TwistedRingInterface_hpp

#include <stdio.h>
#include "ofMain.h"


struct Status{
    char id;//tri-id
    bool sw;//switch on/off
    char pos;//potentio-meter
};

class TwistedRingInterface{
public:
    string port;
    bool connected=false;
    int nBytesRead = 0;
    ofSerial serial;
    char bytesReadString[4];
    Status status;

    TwistedRingInterface();
    ~TwistedRingInterface();
   
    bool open(string);
    void update();
    
};




#endif /* TwistedRingInterface_hpp */
