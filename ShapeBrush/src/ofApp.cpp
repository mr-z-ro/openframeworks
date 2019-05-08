#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(0);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
        // Rectangle Brush
//        ofSetRectMode(OF_RECTMODE_CENTER);
//
//        int numRecs = 10;
//        for (int i=0; i<numRecs; i++) {
//            ofSetColor(ofRandom(50, 255));
//            float width = ofRandom(5, 20);
//            float height = ofRandom(5, 20);
//            float distance = ofRandom(30);
//            float angle = ofRandom(ofDegToRad(360.0));
//            float xOffset = distance * cos(angle);
//            float yOffset = distance * sin(angle);
//            ofDrawRectangle(ofGetMouseX()+xOffset, ofGetMouseY()+yOffset, width, height);
//        }
        
        // Circle Brush
//        int maxRadius = 30;
//        int radiusStepSize = 1;
//        int alpha = 3;
//        int maxOffsetDistance = 100;
//        for (int r=maxRadius; r>0; r-=radiusStepSize) {
//            float angle = ofRandom(ofDegToRad(360.0));
//            float distance = ofRandom(maxOffsetDistance);
//            float xOffset = distance * cos(angle);
//            float yOffset = distance * sin(angle);
//            ofColor myBlue(0, 103, 255, alpha);
//            ofColor myGreen(0, 255, 103, alpha);
//            ofColor inBetween = myBlue.getLerped(myGreen, ofRandom(1.0));
//            ofSetColor(inBetween);
//            ofDrawCircle(ofGetMouseX()+xOffset, ofGetMouseY()+yOffset, r);
//        }
        
        // Line Brush
//        int numLines = 30;
//        int minRadius = 25;
//        int maxRadius = 125;
//        for (int i=0; i<numLines; i++) {
//            float angle = ofRandom(ofDegToRad(360.0));
//            float distance = ofRandom(minRadius, maxRadius);
//            float xOffset = cos(angle) * distance;
//            float yOffset = sin(angle) * distance;
//            float alpha = ofMap(distance, minRadius, maxRadius, 50, 0);  // Make shorter lines more opaque
//            ofSetColor(255, alpha);
//            ofDrawLine(ofGetMouseX(), ofGetMouseY(), ofGetMouseX()+xOffset, ofGetMouseY()+yOffset);
//        }
        
        // Triangle Brush
        int numTriangles = 10;
        int minOffset = 5;
        int maxOffset = 40;
        int alpha = 50;
        for (int t=0; t<numTriangles; t++) {
            float offsetDistance = ofRandom(minOffset, maxOffset);
            
            ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
            
            ofVec2f p1(0, 3);
            ofVec2f p2(30, 0);
            ofVec2f p3(0, -3);
            
            float rotation = ofRandom(360);
            p1.rotate(rotation);
            p2.rotate(rotation);
            p3.rotate(rotation);
            
            ofVec2f triangleOffset(offsetDistance, 0.0);
            triangleOffset.rotate(rotation);
        
            p1 += mousePos + triangleOffset;
            p2 += mousePos + triangleOffset;
            p3 += mousePos + triangleOffset;
            
            ofColor myBlue(0, 103, 255, alpha);
            ofColor myGreen(0, 255, 103, alpha);
            ofColor inBetween = myBlue.getLerped(myGreen, ofRandom(1.0));
            ofSetColor(inBetween);
            ofDrawTriangle(p1, p2, p3);
        }
    }
    
    
    if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {
        ofBackground(0);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        ofSaveScreen("ofScreenshot_" + ofGetTimestampString() + ".png");
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
