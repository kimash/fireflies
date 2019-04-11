#include "ofApp.h"
#define NUM_FLIES 600

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    ofDisableArbTex();
    ofLoadImage(texture, "dot.png");
    
    for(int i = 0; i < NUM_FLIES; i++) {
        points.push_back(ofVec3f(ofRandomWidth(), ofRandomHeight(), ofRandomHeight()));
        sizes.push_back(ofVec3f(ofRandom(10, 90)));
        Firefly f;
        fireflies.push_back(f);
    }
    
    vbo.setVertexData(&points[0], points.size(), GL_STREAM_DRAW);
    vbo.setNormalData(&sizes[0], sizes.size(), GL_STREAM_DRAW);
    
    shader.load("shaders/shader");

}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < points.size(); i++){
        fireflies[i].update(points[i]);
    }
    vbo.updateVertexData(&points[0], points.size());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(0), ofColor(3, 12, 66), OF_GRADIENT_LINEAR);
    glDepthMask(GL_FALSE);
    
    ofSetColor(200, 255, 90);
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofEnablePointSprites();
    
    shader.begin();
    texture.bind();
    vbo.draw(GL_POINTS, 0, points.size());
    texture.unbind();
    
    shader.end();
    
    ofDisablePointSprites();
    ofDisableBlendMode();
    
    glDepthMask(GL_TRUE);
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
