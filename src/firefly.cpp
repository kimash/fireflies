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
    pos.set(pos.x + 1, startY + amp*cos(TWO_PI * freq * pos.x), pos.z);
    
    if (pos.x > ofGetWidth()) {
        pos.set(0, startY + amp*cos(TWO_PI * freq * pos.x), pos.z);
    }
}
