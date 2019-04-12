//
//  firefly.cpp
//  fireflies
//
//  Created by Kim Ash on 5/23/17.
//
//

#include <stdio.h>
#include <firefly.h>

#define MAX_SPEED 2.0

Firefly::Firefly()
{
    drag = ofRandom(0.97, 0.99);
    
    noiseVal = ofRandom(-1000, 1000);
    
    velocity = ofVec3f(ofRandom(-MAX_SPEED, MAX_SPEED), ofRandom(-MAX_SPEED, MAX_SPEED), 0);
}

void Firefly::update(ofVec3f& pos)
{
    acceleration.x = ofSignedNoise(noiseVal, pos.y * 0.05) * 0.5;
    
    acceleration.y = ofSignedNoise(noiseVal, pos.x * 0.006) * 0.05 + 0.12;
    
    velocity *= drag;
    velocity += acceleration * 0.4;
    
    pos -= velocity;
    
    // keep firefly from disappearing offscreen
    if(pos.y < 0){
        pos.y += ofGetHeight();
    }
    
    if(pos.x > ofGetWidth()){
        pos.x -= ofGetWidth();
    }
    
    if(pos.x < 0){
        pos.x += ofGetWidth();
    }
    
}
