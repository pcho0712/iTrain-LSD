#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    ofBackground(255, 255, 255);
    
#ifndef DEBUG_TRI
    //set TRI
    tri.open("tty.usbmodem1421");
#else
    debugStatus[0] = Status();
    debugStatus[1] = Status();
#endif
    
#ifndef DEBUG_RED
    //set RED
    red0.setID((int)0);
    red0.open("tty.usbserial-A105AC6A");
    red1.setID((int)1);
    red1.open("tty.usbserial-A105ABLP");
    red2.setID((int)2);
    red2.open("tty.usbserial-AK05ATII");
#endif
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //TRI loding
    tri.update();
    
    //GameManager
    gm.updateInputStatus(tri.status);
//    gm.updateInputStatus(debugStatus);
    gm.updateGameLogic();
    gm.updateWindowBuffer();
    
    //RED buffer upload to LED buffer
    ldisp.renderData(gm.dataWindow1.buffer, gm.dataWindow2.buffer, gm.gameWindow.buffer);
    ldisp.uploadData();
    
    //Serial Communication
    red0.sendData(ldisp);
    red1.sendData(ldisp);
    red2.sendData(ldisp);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ldisp.display(ofPoint(100,200));
    ldisp.lmats[5]->dispMatrix(ofPoint(100,400),200);//debug
    tri.draw();
    gm.dispDebug();//debug

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    char ch = (char) key;

//    if(ch == '1')  ldisp.moveDataToLeft01();
//    if(ch == '2')  ldisp.moveDataToRight01();

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
    debugStatus[0].sw = true;

    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    debugStatus[0].sw = false;

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
