//
//  VSyn.hpp
//  vSyn
//
//  Created by sonir on 9/8/17.
//
//

#ifndef VSyn_hpp
#define VSyn_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxOsc.h"
#include "shape.h"
#include "osc2shape.hpp"

#define PORT 57137
#define NUM_MSG_STRINGS 20

#define CONTAINER_MAX 128

//typedef enum shape_type {CIRCLE, TRIANGLE, SQUARE, RECT, LINE, ARC, WAVE } shape_type;
//
//typedef struct shapeContainer {
//    
//    shape_type type;
//    bool active;
//    int uid;
//    float x1;
//    float y1;
//    float x2;
//    float y2;
//    
//    float size;
//    float height;
//    float angle;
//    bool fill;
//
//    
//    
//} shapeContainer;


class VSyn {
 
    public:
        void setup();
        void update();
    
        shapeContainer shapes[CONTAINER_MAX];
        ofxOscReceiver receiver;
        int current_msg_string;
        string msg_strings[NUM_MSG_STRINGS];
        float timers[NUM_MSG_STRINGS];
    
    private:
        void initShapes(int max_num);
    
};

#endif /* VSyn_hpp */
