#pragma once

#include "ofMain.h"
#include "firefly.h"
#include "ofxSyphon.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        vector <ofVec3f> points;
        vector <ofVec3f> sizes;
        vector<Firefly> fireflies;
    
        ofVbo vbo;
        ofShader shader;
        ofTexture texture;
        ofFbo fbo;
    
        ofxSyphonServer server;
//        ofxSyphonClient client;
};
