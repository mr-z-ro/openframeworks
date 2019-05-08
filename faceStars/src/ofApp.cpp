#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    vid = ofVideoGrabber();
    //vid.listDevices();
    vid.initGrabber(640, 480);
    vid.setDeviceID(0);
    
    int N = 800;
    for (int i=0; i<N; i++) {
        int w = ofGetWidth();
        int h = ofGetHeight();
        
        ofVec3f pos;
        pos.x = ofRandom(-w/2, w/2);
        pos.y = ofRandom(-h/2, h/2);
        pos.z = ofRandom(w/4, -3*w/4);
        mesh.addVertex(pos);
        mesh.addColor(ofRandom(220));
        mesh.setMode(OF_PRIMITIVE_LINES);
        
        thicknesses.push_back(ofRandom(2, 5));
    }
    
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; a++) {
        ofVec3f v_a = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; b++) {
            ofVec3f v_b = mesh.getVertex(b);
            if (v_b.distance(v_a) < 65) {
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    vid.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofPushMatrix();
    float a_x = ofMap(ofGetMouseY(), 0, ofGetHeight(), -PI/12.0, PI/12.0);
    float a_y = ofMap(ofGetMouseX(), 0, ofGetWidth(), PI/12.0, -PI/12.0);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    vid.draw(-vid.getWidth()/4, -vid.getHeight()/4, vid.getWidth()/2, vid.getHeight()/2);
    ofRotateXRad(a_x);
    ofRotateYRad(a_y);
    mesh.draw();
    for (int i=0; i<mesh.getNumVertices(); i++) {
        ofSetColor(mesh.getColor(i));
        ofDrawSphere(mesh.getVertex(i), thicknesses[i]);
    }
    ofPopMatrix();
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
