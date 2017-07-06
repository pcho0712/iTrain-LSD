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
#include "Status.hpp"



class TwistedRingInterface{
public:
    string port;
    bool connected=false;
    ofSerial serial;
    Status status[2];//tri0

    
    //debuf
    static constexpr unsigned char START_BYTE = 0xFF;
    unsigned char returnedBytes[256];

    TwistedRingInterface();
    ~TwistedRingInterface();
   
    bool open(string);
    void update();
    void draw();
    string moduleInfo(int);
    
};




#endif /* TwistedRingInterface_hpp */
