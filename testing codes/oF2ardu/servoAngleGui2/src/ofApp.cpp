#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0, 0, 0);
    ofSetWindowTitle("Servo Control Panel");
    
    serial.setup("/dev/cu.usbmodem2101", 115200);
    
    gui.setup();
    gui.add(leftSlider.setup("Left Angle:", 135, 0, 254));
}

//--------------------------------------------------------------
void ofApp::update(){
//    unsigned char angle = angleSlider;
    
    serial.writeByte((char)leftSlider);
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    ofSetColor(255, 255, 255);
    ofFill();
    ofDrawCircle(leftSlider, 150, 30);
    
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

