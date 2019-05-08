//
//  Star.hpp
//  faceStars
//
//  Created by M G on 2/8/19.
//

#ifndef Star_hpp
#define Star_hpp

#include <stdio.h>
#include "ofMain.h"

class Star {
    public:
        ofVec3f pos;
        int m_s;
        int m_w;
    
        Star(int x, int y, int z, int s, int w);
        void draw();
        void drawLines(vector<Star> other_stars, int max_index, int thresh);
};

#endif /* Star_hpp */
