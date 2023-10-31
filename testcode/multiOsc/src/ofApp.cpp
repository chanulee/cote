#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    osc.setup(PORT);
//    serial.setup("/dev/cu.usbmodem101", 9600);
}

//--------------------------------------------------------------
void ofApp::update(){
    while (osc.hasWaitingMessages() ) {
        ofxOscMessage m;
        osc.getNextMessage(&m);
        if (m.getAddress() == "/faces/arr") {

        }
        else if(m.getAddress() == "/td/sound"){
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(testColor);
    ofFill();
    ofDrawCircle(500, 500, wekClass * 100);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
