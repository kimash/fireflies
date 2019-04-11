//
//  firefly.cpp
//  fireflies
//
//  Created by Kim Ash on 5/23/17.
//
//

#include <stdio.h>
#include <firefly.h>

Firefly::Firefly()
{
    drag = ofRandom(0.97, 0.99);
    
    noiseVal = ofRandom(-10000, 10000);
    
    velocity = ofVec3f(ofRandom(-3.9, 3.9), 3.0 * fabs(ofRandom(-3.9, 3.9)), 0);
    
}

void Firefly::update(ofVec3f& pos)
{
    acceleration.x = ofSignedNoise(noiseVal, pos.y * 0.04) * 0.6;
    
    acceleration.y = ofSignedNoise(noiseVal, pos.x * 0.006, ofGetElapsedTimef()*0.2) * 0.09 + 0.18;
    
    velocity *= drag;
    velocity += acceleration * 0.4;
    
    if(pos.y + velocity.y > ofGetHeight()){
        pos.y -= ofGetHeight();
    }
    
    pos += velocity;
}
