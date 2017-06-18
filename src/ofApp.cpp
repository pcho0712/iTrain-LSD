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
    lmat.setData(font['a'].data);
//        lmat.setData(hira[3].data);

    
    //set
    tri1.open("/dev/tty.usbmodem1411");
    
    
    
    //test
//    wchar_t hira = L'あ';//wide-character
//    cout << L'あ';
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(ofGetFrameNum()%10 == 0){
        //    ldisp.moveDataToRight01();
        ldisp.moveDataToLeft01();
    }
    
    
    
    ldisp.uploadData();
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    lmat.dispMatrix(ofPoint(500,300),200);
    
    
    ldisp.display(ofPoint(100,100));
    ldisp.lmats[0]->dispMatrix(ofPoint(100,300),200);//debug
    
    
    //    ofDrawCircle(ofPoint(ofGetMouseX(),ofGetMouseY()), 10);// debug
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    char ch = (char) key;
    lmat.setData(font[ch].data);
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
