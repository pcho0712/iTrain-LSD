//
//  REDModule.cpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/06/28.
//
//

#include "REDModule.hpp"


REDModule::REDModule(){

}



REDModule::~REDModule(){
    
}



bool REDModule::open(string _port){
    port = _port;// "/dev/tty.usbmodem1411"
    if(serial.setup(port,115200)){
        connected = true;
        return true;
    }else{
        connected = false;
        return false;
    }
    
}

void REDModule::setID(int _id){
    id=_id;
    for(int i=0;i<8;i++){
        led_id[i] = id*8+i;
    }
}


void REDModule::sendData(LineDisplay& ld){

    serial.writeByte(START_BYTE);//start-byte
    for(int iLed=0;iLed<8;iLed++){
        for(int iLine=0;iLine<8;iLine++){
           unsigned char ch = ld.lmats[led_id[iLed]]->getLine(iLine);
            serial.writeByte(ch);         
        }
    }
    
    
}






