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
        //    if(serial.setup(port,9600)){
        connected = true;
        return true;
    }else{
        connected = false;
        return false;
    }
    
}

void REDModule::setID(int _id){
    id=_id;
    int s = id*8;
    
    
    //sequence
    //    led_id[0]=s+6;
    //    led_id[1]=s+5;
    //    led_id[2]=s+4;
    //    led_id[3]=s+3;
    //    led_id[4]=s+2;
    //    led_id[5]=s+1;
    //    led_id[6]=s+0;
    led_id[0]=s+7;
    led_id[1]=s+6;
    led_id[2]=s+5;
    led_id[3]=s+4;
    led_id[4]=s+3;
    led_id[5]=s+2;
    led_id[6]=s+1;
    led_id[7]=s+0;
    
    
    //    for(int i=0;i<8;i++){
    //        led_id[i] = id*8+i;
    //    }
    
    
}



void REDModule::sendData(LineDisplay& ld){
    
    //send 64 Byte for arduino
    
    //former 1+32 byte
    serial.writeByte(START_FORMER_BYTE);//start-byte
    for(int iLed=0;iLed<4;iLed++){
        for(int iLine=0;iLine<8;iLine++){
            unsigned char ch = ld.lmats[led_id[iLed]]->getColumn(iLine);
            serial.writeByte(ch);
        }
    }
    
    //latter 1+32 byte
    serial.writeByte(START_LATTER_BYTE);//start-byte
    for(int iLed=4;iLed<8;iLed++){
        for(int iLine=0;iLine<8;iLine++){
            unsigned char ch = ld.lmats[led_id[iLed]]->getColumn(iLine);
            serial.writeByte(ch);
        }
    }
    
}



void REDModule::readForDebug(){
    
    // 送られてきた文字列を表示
    string msg;
    if(serial.available()>=0){
        msg += "connected status: "+ofToString(serial.readByte()) + "\n";
        //    msg += ofToString(nBytesRead) + " [bytes]" + "\n";
        ofSetColor(0);
        ofDrawBitmapString(msg, 300, 50);
    }
}





