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
    if(serial.setup(port,115200)){
        connected = true;
        return true;
    }else{
        connected = false;
        return false;
    }
}


void TwistedRingInterface::update(){
    
    
    //まずはじめに：シリアルバッファがたまりすぎていたら捨てる作業
    while(serial.available()>10) serial.readByte();
    
    if(serial.available()>1){
        
        //parse original protocol
        
        if(serial.readByte() == START_BYTE){  //start-byte
            unsigned char byte = serial.readByte();            //data-byte
            cout << static_cast<std::bitset<8>>(byte) << endl;

            //parsing
            char id = (byte & 0x80)>>7;//MSB
            char sw = (byte & 0x40)>>6 ? true : false;//MSB-1
            char sign = (byte & 0x20) <<2;//MSB-2: sign of position
            signed char pos = sign | (byte & 0x1F);
			if (pos < 0) pos = -(pos + 128);
			//LSB to MSB-3
//            cout << static_cast<std::bitset<8>>(pos) << endl;

            
            //store
            status[id].id = id;
            status[id].sw = sw;
            status[id].pos = pos;
        }
        
    }
    
    
}


void TwistedRingInterface::draw(){
    
    // 送られてきた文字列を表示
    string msg;
    if(connected){
        msg += "connected status: "+ofToString(connected) + "\n";
        msg += "port: "+ofToString(port) + "\n";
        msg += "serial.available(): " +ofToString(serial.available())+ "\n";
        msg+= moduleInfo(0);
        msg+= moduleInfo(1);
    }else{
        msg += "no connected TRI!";
    }
    //    msg += "read: " + ofToString(bytesReadString);
    ofSetColor(0);
    ofDrawBitmapString(msg, 100, 50);
    
}

string TwistedRingInterface::moduleInfo(int i){
    string msg;
    
    //status
        msg += "status id: "+ to_string(status[i].id) + ", ";
        msg += "sw: "+ to_string(status[i].sw) + ", ";
        msg += "pos: "+ to_string(status[i].pos) + "\n";
    return msg;
}





