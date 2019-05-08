#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    minBright = 100;
    maxBright = 200;
    sqWidth = 20;
    dir = 0;
    
    ofSetFrameRate(60);
    easyCam.setDistance(1000);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(10);
    
    if (dir == 0) {
        ofResetElapsedTimeCounter();
    }
    
    easyCam.begin();
    float newDist = easyCam.getDistance()-dir*2;
    if (newDist < 20 || newDist > 1000) {
        dir = -dir;
    }
    easyCam.setDistance(newDist);
    for (int i=0; i<ofGetWidth()/sqWidth; i+=1) {
        for (int j=0; j<ofGetHeight()/sqWidth; j+=1) {
            int col = ofRandom(minBright, maxBright);
            int colNoise = ofNoise(i*col, j*col);
            
            ofSetColor(60, 20, 150);
            
            int depth = -abs(sin(ofGetElapsedTimef()/80 * (i*j/4)+1/(i*j+1)) * ofMap(colNoise, minBright, maxBright, 50, 200));
            
            ofBoxPrimitive box = ofBoxPrimitive(sqWidth, sqWidth, depth);
            ofMesh mesh = box.getMesh();
            mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
            
            
            ofPushMatrix();
            ofTranslate(3*ofGetWidth()/5-i*(sqWidth*1.25), 3*ofGetHeight()/5-j*(sqWidth*1.25), -depth/2);
            mesh.draw();
            ofPopMatrix();
            
        }
    }
    easyCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    dir = 1;
    ofResetElapsedTimeCounter();
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
