#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    for(int i = 0; i < this->shapeNum; i++){
        this->positions[i] = vec2(ofRandom(-ofGetWidth(),ofGetWidth()),ofRandom(-ofGetHeight(),ofGetHeight()));
        this->radius[i] = ofRandom(0.1);
        this->incrementRadius[i] = ofRandom(0.005,0.02);
        this->circleWidth[i] = ofRandom(0.001,0.05);
        this->circleColors[i] = vec3(ofRandom(1.0),ofRandom(1.0),ofRandom(1.0));
    }
    this->current.allocate(ofGetWidth(),ofGetHeight());
    
    this->shader.load("Vertex.vert","Fragment.frag");
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < this->shapeNum; i++){
        this->radius[i] += this->incrementRadius[i];
        if(this->radius[i] >= 2.5){
            this->positions[i] = vec2(ofRandom(-ofGetWidth(),ofGetWidth()),ofRandom(-ofGetHeight(),ofGetHeight()));
            this->radius[i] = 0.0;
            this->circleWidth[i] = ofRandom(0.001,0.05);
            this->circleColors[i] = vec3(ofRandom(1.0),ofRandom(1.0),ofRandom(1.0));
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    this->current.begin();
    
    this->shader.begin();
    this->shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
    this->shader.setUniform1f("time",ofGetElapsedTimef());
    this->shader.setUniform2fv("positions", &this->positions[0].x,this->shapeNum);
    this->shader.setUniform1fv("radius", &this->radius[0],this->shapeNum);
    this->shader.setUniform1fv("circleWidth", &this->circleWidth[0],this->shapeNum);
    this->shader.setUniform3fv("circleColors", &this->circleColors[0].x,this->shapeNum);
    this->shader.setUniformTexture("fbo", this->current.getTexture(), 1);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    this->shader.end();
    this->current.end();
    
    this->current.draw(0,0);
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
