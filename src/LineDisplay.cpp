//
//  LineDisplay.cpp
//  test-nishioka
//
//  Created by 吉田貴寿 on 2017/06/16.
//
//

#include "LineDisplay.hpp"



LineDisplay::LineDisplay(){
    
    for(int idx=0;idx<length;idx++){
        lmats.push_back(new LEDMatrix());
        setRandomData();
        //        lmats[idx]->setMatSize(120);
    }
//    uploadData();
    
}


LineDisplay::~LineDisplay(){
}


void LineDisplay::uploadData(){
    //LEDMatrixへの割付
    for(int idx=0;idx<length;idx++){
        for(int y=0;y<8;y++){
            for(int x=0;x<8;x++){
                lmats[idx]->data[y][x] = data[y][x+idx*8];
            }
        }
    }
}


void LineDisplay::display(ofPoint ofp){
    for(int idx=0;idx<length;idx++){
        lmats[idx]->dispMatrix(ofp + ofPoint(idx*matSize,0),matSize);
    }
    
    
}


void LineDisplay::setRandomData(){
    for(int y=0;y<dispHeight;y++){
        for(int x=0;x<dispWidth;x++){
            data[y][x]= ofRandom(0,1)>0.5 ? 1:0;
        }
    }
    
}


void LineDisplay::moveDataToRight01(){
    int buf=0;
    for(int y=0;y<dispHeight;y++){
        buf = data[y][dispWidth-1];
        
        for(int x=dispWidth-1;x>0;x--){
            
            data[y][x]=data[y][x-1];
        }
        data[y][0] = buf;
    }
}


void LineDisplay::moveDataToLeft01(){
    int buf=0;
    for(int y=0;y<dispHeight;y++){
        buf = data[y][0];
        
        for(int x=0;x<dispWidth-1;x++){
            
            data[y][x]=data[y][x+1];
        }
        data[y][dispWidth-1] = buf;
    }
}

void LineDisplay::addDataAtLast(int d[8][8]){
    int idx = length-1;
    for(int y=0;y<8;y++){
        for(int x=0;x<8;x++){
            data[y][x+idx*8]=d[y][x];
        }
    }
        
}






