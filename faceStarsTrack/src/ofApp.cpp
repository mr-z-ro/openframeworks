#include "ofApp.h"
using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
    a_x = 0;
    a_y = 0;
    zoom = 0;
    showDebugVid = false;
    
    vid = ofVideoGrabber();
    //vid.listDevices();
    vid.initGrabber(1200, 800);
    vid.setDeviceID(0);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    finder.setup("haarcascade_frontalface_default.xml");
    finder.setPreset(ObjectFinder::Fast);
    finder.getTracker().setSmoothingRate(.3);
    ofEnableAlphaBlending();
    
    int N = 800;
    for (int i=0; i<N; i++) {
        int w = ofGetWidth();
        int h = ofGetHeight();
        
        ofVec3f pos;
        pos.x = ofRandom(-w/2, w/2);
        pos.y = ofRandom(-h/2, h/2);
        pos.z = ofRandom(w/4, -3*w/4);
        mesh.addVertex(pos);
        ofColor col = ofColor();
        col.set(ofRandom(220.0));
        mesh.addColor(col);
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
    if(vid.isFrameNew()) {
        finder.update(vid);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    if (showDebugVid) {
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2-vid.getWidth()/2, ofGetHeight()/2-vid.getHeight()/2);
        vid.draw(0, 0, vid.getWidth(), vid.getHeight());
        finder.draw();
        ofPopMatrix();
    }
    
    if (finder.size() > 0) {
        ofRectangle object = finder.getObjectSmoothed(0);
        a_x = ofMap(object.getY() - ofGetHeight()/2, 0, ofGetHeight(), -PI/12.0, PI/12.0);
        a_y = ofMap(object.getX() - ofGetWidth()/2, 0, ofGetWidth(), -PI/9.0, PI/9.0);
        zoom = ofMap(object.getWidth(), 200, 600, -200, 1200);
    }
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, zoom);
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
    if (key == 'd') {
        showDebugVid = !showDebugVid;
    }
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
