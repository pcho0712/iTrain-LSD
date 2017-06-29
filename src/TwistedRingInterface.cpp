//
//  TwistedRingInterface.cpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/06/18.
//
//

#include "TwistedRingInterface.hpp"




TwistedRingInterface::TwistedRingInterface(){

}


TwistedRingInterface::~TwistedRingInterface(){
    
}


bool TwistedRingInterface::open(string str){
    port = str;// "/dev/tty.usbmodem1411"
    if(serial.setup(port,9600)){
        connected = true;
        return true;
    }else{
        connected = false;
        return false;
    }
}


void TwistedRingInterface::update(){
    
    
    
    if(serial.available()>0){
        unsigned char byte = serial.readByte();
        cout << static_cast<std::bitset<8> >(byte) <<endl;

        status.id = (byte & 0x80)>>7;//MSB
        status.sw = (byte & 0x40)>>6 ? true : false;//MSB-1
        char sign = byte & 0x20 <<2;//MSB-2: sign of position
        status.pos = sign|(byte & 0x1F);//LSB to MSB-3
    }
 
    
}


void TwistedRingInterface::draw(){
    
    // 送られてきた文字列を表示
    string msg;
    msg += "connected status: "+ofToString(connected) + "\n";
    msg += "port: "+ofToString(port) + "\n";
        msg += "status id: "+ to_string(status.id) + "\n";
    msg += "status sw: "+ to_string(status.sw) + "\n";
    msg += "status pos: "+ to_string(status.pos) + "\n";

//    msg += "read: " + ofToString(bytesReadString);
    ofSetColor(0);
    ofDrawBitmapString(msg, 100, 50);
    
}





