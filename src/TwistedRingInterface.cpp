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
    
    nBytesRead = 0;
    int nRead = 0;
    char bytesRead[3];
    unsigned char bytesReturned[3];
    
    memset(bytesReturned, 0, 3);
    memset(bytesReadString, 0, 4);
    
    // シリアル通信で受け取ったデータを読み込む
    while ((nRead = serial.readBytes(bytesReturned, 3)) > 0) {
        
        nBytesRead = nRead;
    };
    
    if (nBytesRead > 0) {
        
        memcpy(bytesReadString, bytesReturned, 3);
        string x = bytesReadString;
    }
    
}

