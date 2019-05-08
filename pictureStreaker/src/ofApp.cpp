#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("neuromancer.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int w = img.getWidth();
    int h = img.getHeight();
    for(int y = h-1; y >= 0; y -= 2) {
        for(int x = w-1; x >= 0; x -= 2) {
            ofColor c = img.getColor(x, y);
            ofSetColor(c);
            int maxL = ofMap(ofGetMouseY(), 0, ofGetHeight(), 2, h);
            int streakLength = ofMap(c.getSaturation(), 255, 0, 2, maxL);
            ofLine(x, y, x, y+streakLength);
            ofLine(x+1, y, x+1, y+streakLength);
        }
    }
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
