#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    meshSize = 3;
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    float xnoise = 0.0;
    float ynoise = 0.0;
    float inc = 0.1;
    
    for (int y=0; y<ofGetHeight(); y+=meshSize) {
        for (int x=0; x<ofGetWidth(); x+=meshSize) {
            float znoise = ofNoise(xnoise++, ynoise)*10;
            mesh.addVertex(ofVec3f(x,y,znoise));
            noises.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
        }
        ynoise++;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<mesh.getNumVertices(); ++i) {
        ofVec3f vert = mesh.getVertex(i);
        
        float time = ofGetElapsedTimef();
        float timeScale = 5.0;
        float displacementScale = 0.75;
        
        ofVec3f timeOffsets = noises[i];
        
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        
        if (i % (ofGetWidth()/meshSize) != 0) {
            mesh.setVertex(i, vert);
            mesh.addIndex(i);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(40, 40, 80);
    
    easyCam.begin();
        ofPushMatrix();
            ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
            mesh.draw();
        ofPopMatrix();
    easyCam.end();
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
