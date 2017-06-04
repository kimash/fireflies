//
//  firefly.h
//  fireflies
//
//  Created by Kim Ash on 5/23/17.
//
//

#ifndef fireflies_firefly_h
#define fireflies_firefly_h

#include <ofMain.h>

class Firefly {

public:
    Firefly();
    ~Firefly(){}
    
    void setup(ofVec3f pos_, float size_, float amp_, float freq_);
    void update();
    ofVec3f getPos() {return pos;}
    ofVec3f getSize() {return size;}
    
    
protected:
    ofVec3f pos;
    ofVec3f size;
    float amp;
    float freq;
    float startY;
    
};

#endif
