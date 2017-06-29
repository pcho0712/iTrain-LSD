//
//  REDModule.hpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/06/28.
//
//

#ifndef REDModule_hpp
#define REDModule_hpp

#include <stdio.h>
#include "ofMain.h"
#include "LineDisplay.hpp"

class REDModule{
public:
    
    string port;
    ofSerial serial;
    char id;//module id
    char led_id[8];//
    bool connected=false;
    
    static constexpr unsigned char START_BYTE = 0xAA;
    
    REDModule();
    ~REDModule();
    
    bool open(string);
    void setID(int);
    void sendData(LineDisplay&);
    void readForDebug();
    
};







#endif /* REDModule_hpp */
