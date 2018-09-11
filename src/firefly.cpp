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
    amp = 1.0;
    freq = 1.0;
    startY = 0.0;
}

void Firefly::setup(ofVec3f pos_, float size_, float amp_, float freq_)
{
    pos = pos_;
    size = ofVec3f(size_);
    amp = amp_;
    freq = freq_;
    startY = pos.y;
}

void Firefly::update()
{
    pos.rotate(0.5, ofVec3f(0, 0, ofGetWidth()));
//    pos.set(pos.x + 1, startY + amp*cos(TWO_PI * freq * pos.x), pos.z);
//    
//    if (pos.x > ofGetWidth()) {
//        pos.set(0, startY + amp*cos(TWO_PI * freq * pos.x), pos.z);
//    }
}
