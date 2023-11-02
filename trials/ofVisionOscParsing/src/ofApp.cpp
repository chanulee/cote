#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    osc.setup(PORT);
    wekSender.setup("localhost", 6448);
    
    serial.setup("/dev/cu.usbmodem2101", 115200);

}

//--------------------------------------------------------------
void ofApp::update(){
    ofxOscMessage wekMessage;
    wekMessage.setAddress("/wek/inputs");  // Default address for Wekinator inputs
    
    while (osc.hasWaitingMessages() ) {
        ofxOscMessage m;
        osc.getNextMessage(&m);
        
        if (m.getAddress() == "/faces/arr") {
            for (int i = 4; i <= 231; i++) {
                if (i % 3 != 0) { // Skip scores: 3, 6, 9, 12, 15, 18...
                    int faceData = m.getArgAsInt(i);
                    ofLog() << "facedata: " << faceData;
                    wekMessage.addIntArg(faceData);
                }
            }
        }
    }
    
    if(wekMessage.getNumArgs() > 150) {
        int numArgs = wekMessage.getNumArgs();
        ofLog() << "Number of arguments in OSC message: " << numArgs;
        wekSender.sendMessage(wekMessage);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(faceNo, 500, 20);
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
