//
//  Star.cpp
//  faceStars
//
//  Created by M G on 2/8/19.
//

#include "Star.hpp"

Star::Star(int x, int y, int z, int s, int w) {
    pos.x = x;
    pos.y = y;
    pos.z = z;
    m_s = s;
    m_w = w;
}

void Star::draw() {
    ofSetColor(m_s);
    ofSetLineWidth(m_w);
    ofDrawSphere(pos.x, pos.y, pos.z, m_s);
}

void Star::drawLines(vector<Star> other_stars, int max_index, int thresh) {
    for (int i; i<max_index; i++) {
        Star star = other_stars[i];
        if (ofDist(pos.x, pos.y, pos.z, star.pos.x, star.pos.y, star.pos.z) < thresh) {
            ofSetLineWidth(min(m_s, star.m_s));
            ofDrawLine(pos.x, pos.y, pos.z, pos.x, pos.y, pos.z);
        }
    }
}
