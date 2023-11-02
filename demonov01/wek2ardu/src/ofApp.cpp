#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Servo Control Panel");
    
    osc.setup(PORT);
//    wekSender.setup("localhost", 6448);
    
    serial.setup("/dev/cu.usbmodem2101", 115200);

}

//--------------------------------------------------------------
void ofApp::update(){
    ofxOscMessage wekMessage;
//    wekMessage.setAddress("/wek/inputs");  // Default address for Wekinator inputs
    
    while (osc.hasWaitingMessages() ) {
        ofxOscMessage m;
        osc.getNextMessage(&m);
        
        if (m.getAddress() == "/wek/outputs") {
            
            
//            for (int i = 4; i <= 231; i++) {
//                if (i % 3 != 0) { // Skip scores: 3, 6, 9, 12, 15, 18...
//                    int faceData = m.getArgAsInt(i);
//                    ofLog() << "facedata: " << faceData;
//                    wekMessage.addIntArg(faceData);
//                }
//            }

            /*------IF WEKINATOR MODEL IS CLASSIFIER------*/
            wekClass = m.getArgAsInt(0);
//            ofLog() << "wekClass: " << wekClass;
            serial.writeByte((char)wekClass);
            
            /*------IF WEKINATOR MODEL IS REGRESSOR------*/
//            wekRegFloat = m.getArgAsFloat(0)+1; // -1 ~ 1 -> 0~2
//            wekRegRound = roundf(wekReg*100); //0~200
//            wekReg = ofMap(wekRegRound, 0, 200, 0, 254); //int 0~254
            
            
        }
    }
    
//    if(wekMessage.getNumArgs() > 150) {
//        int numArgs = wekMessage.getNumArgs();
//        ofLog() << "Number of arguments in OSC message: " << numArgs;
//        wekSender.sendMessage(wekMessage);
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(wekReg, 500, 20);
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

