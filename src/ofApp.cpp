#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    // load the texure
    ofDisableArbTex();
    ofLoadImage(texture, "dot.png");
    
    for(int i = 0; i < 200; i++ ) {
        Firefly f;
        f.setup(ofVec3f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(500)), ofRandom(10, 70), 30, PI/3);
        fireflies.push_back(f);
        points.push_back(f.getPos());
        sizes.push_back(f.getSize());
    }
    
    // upload the data to the vbo
    int total = (int)points.size();
    vbo.setVertexData(&points[0], total, GL_STREAM_DRAW);
    vbo.setNormalData(&sizes[0], total, GL_STREAM_DRAW);
    
    shader.load("shaders/shader");

}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < fireflies.size(); i++){
        fireflies[i].update();
        points[i].set(fireflies[i].getPos());
    }
    vbo.updateVertexData(&points[0], points.size());
}

//--------------------------------------------------------------
void ofApp::draw(){
    glDepthMask(GL_FALSE);
    
    ofSetColor(200, 255, 90);
    
    // this makes everything look glowy :)
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofEnablePointSprites();
    
    // bind the shader and camera
    // everything inside this function
    // will be effected by the shader/camera
    shader.begin();
    
    // bind the texture so that when all the points
    // are drawn they are replace with our dot image
    texture.bind();
    vbo.draw(GL_POINTS, 0, (int)points.size());
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
