#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    ofBackground(255, 255, 255);
    
    
    //create font book
    for(unsigned char ch = 0;ch<128;ch++){
        font[ch] =*new FontTo8x8(ch);
        
    }
    //hiragana font
    for(unsigned char ch = 0;ch<128;ch++){
        unsigned wchar_t hiragana = (wchar_t)ch+ L'あ';
        hira[ch] =*new FontTo8x8(hiragana);
        cout << hiragana << endl;
    }

    
    //set
    tri0.open("/dev/tty.usbmodem1411");
    
    red0.setID((int)0);
    red0.open("tty.usbserial-A105AC8S");
//    red1.setID((int)1);
//    red1.open("/dev/tty.usbmodem1413");
//    red2.setID((int)2);
//    red2.open("/dev/tty.usbmodem1414");
    

    
    //ldisp
//    string str = "hello, everyone!";
    string str = "01234567";
    TextContent tx(str);
    ldisp.setText(tx);
    
    
    
    

    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(ofGetFrameNum()%3 == 0){
        ldisp.moveDataToLeft01();
    }
    
    
    
    ldisp.uploadData();
//    tri0.update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    lmat.dispMatrix(ofPoint(500,300),200);
    
    
    ldisp.display(ofPoint(100,200));
    ldisp.lmats[1]->dispMatrix(ofPoint(100,400),200);//debug
    
    
    //    ofDrawCircle(ofPoint(ofGetMouseX(),ofGetMouseY()), 10);// debug
 
//    tri0.draw();
    
    red0.sendData(ldisp);
//    red1.sendData(ldisp);
//    red2.sendData(ldisp);


    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    char ch = (char) key;
//    lmat.setData(font[ch].data);
    ldisp.addDataAtLast(font[ch].data);
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
