//
//  drawer.hpp
//
//  Created by Hana on 2017/09/08.
//
//

#ifndef drawer_hpp
#define drawer_hpp

#include "ofMain.h"

void circle(float x, float y, float size, int fill);
void triangle(float x, float y, float size, float angle, float fill);
void square(float x, float y, float size, float angle, float fill);
void rect(float x1, float y1, float x2, float y2, float angle, float fill);
void line(float x1, float y1, float x2, float y2, float thick);
void arc(float x1, float y1, float x2, float y2, float height, int direction, float thick);
void wave(float x1, float y1, float x2, float y2, float freq, float amplitude, float thick);

#endif /* drawer_hpp */
