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
    
    void update(ofVec3f& pos);
    
protected:
    ofVec3f velocity;
    ofVec3f acceleration;
    
    float drag;
    float noiseVal;
};

#endif
