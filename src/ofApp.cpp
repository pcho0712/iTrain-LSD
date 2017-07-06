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
    /*for(unsigned char ch = 0;ch<128;ch++){
        unsigned wchar_t hiragana = (wchar_t)ch+ L'あ';
        hira[ch] =*new FontTo8x8(hiragana);
        cout << hiragana << endl;
    }*/
    
    
    //set TRI
    //tri.open("/dev/tty.usbmodem1421");
    tri.open("/dev/tty.usbmodem1431");
    
    //set RED
    red0.setID((int)0);
    //red0.open("tty.usbserial-A105AC8S");
    red0.open("tty.usbserial-A105AC6A");
    red1.setID((int)1);
    red1.open("tty.usbserial-A105ABLP");
    red2.setID((int)2);
    red2.open("tty.usbserial-AK05ATII");
    
    
    
    //ldisp
    //    string str = "hello, everyone!";
    string str = "0-------1-------2-------";
    TextContent tx(str);
    ldisp.setText(tx);
    
    
    
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    //TRI loding
    tri.update();

    
//    if(ofGetFrameNum()%3 == 0){
//        ldisp.moveDataToLeft01();
//    }
    
    //(option) TRI control test
    if(tri.status[0].pos>20)   ldisp.moveDataToLeft01();
    if(tri.status[0].pos<-20)   ldisp.moveDataToRight01();
    if(tri.status[0].sw){
        string str = "--------SWITCH-ON--------";
        TextContent tx(str);
        ldisp.setText(tx);
    }else{
        string str = "0-------1-------2-------";
        TextContent tx(str);
        ldisp.setText(tx);
    }
    
    
    //RED buffer upload to LED buffer
    ldisp.uploadData();
    
    //Serial Communication
    red0.sendData(ldisp);
    red1.sendData(ldisp);
    red2.sendData(ldisp);
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //    lmat.dispMatrix(ofPoint(500,300),200);
    
    
    ldisp.display(ofPoint(100,200));
    ldisp.lmats[1]->dispMatrix(ofPoint(100,400),200);//debug
    
    tri.draw();

    
    
    //    ofDrawCircle(ofPoint(ofGetMouseX(),ofGetMouseY()), 10);// debug
    
    

    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    char ch = (char) key;
    //    lmat.setData(font[ch].data);
//    ldisp.addDataAtLast(font[ch].data);
    
    if(ch == '1')  ldisp.moveDataToLeft01();
    if(ch == '2')  ldisp.moveDataToRight01();


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
