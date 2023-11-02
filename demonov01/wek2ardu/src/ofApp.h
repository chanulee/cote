#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 12000 //OSC Port
/*
 visionOSC default: 9527
 wekinator default: 12000
 */

class ofApp : public ofBaseApp{

    public:
        void setup() override;
        void update() override;
        void draw() override;
        void exit() override;

        void keyPressed(int key) override;
        void keyReleased(int key) override;
        void mouseMoved(int x, int y ) override;
        void mouseDragged(int x, int y, int button) override;
        void mousePressed(int x, int y, int button) override;
        void mouseReleased(int x, int y, int button) override;
        void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
        void mouseEntered(int x, int y) override;
        void mouseExited(int x, int y) override;
        void windowResized(int w, int h) override;
        void dragEvent(ofDragInfo dragInfo) override;
        void gotMessage(ofMessage msg) override;
        
    
    ofxOscReceiver osc;
    ofxOscSender wekSender;
    
    ofSerial serial;
    
    int wekClass = 0;
    float wekRegFloat;
    int wekRegRound;
    int wekReg;
};
