#include "ofApp.h"

void ofApp::setup() {
    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh.enableColors();
    mesh.enableIndices();
    
    ofVec3f top(100.0, 50.0, 0.0);
    ofVec3f left(50.0, 150.0, 0.0);
    ofVec3f right(150.0, 150.0, 0.0);
    
    mesh.addVertex(top);
    mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));
    
    mesh.addVertex(left);
    mesh.addColor(ofFloatColor(0.0, 1.0, 0.0));
    
    mesh.addVertex(right);
    mesh.addColor(ofFloatColor(1.0, 1.0, 0.0));
    
    mesh.addIndex(0);
    mesh.addIndex(1);
    mesh.addIndex(1);
    mesh.addIndex(2);
    mesh.addIndex(2);
    mesh.addIndex(0);
}

void ofApp::draw() {
    ofBackground(0);
    mesh.draw();
}

//--------------------------------------------------------------
void ofApp::update(){

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
