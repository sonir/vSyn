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
#include "drawer.hpp"

#define PORT 57137
#define NUM_MSG_STRINGS 20

#define CONTAINER_MAX 128 //Size of Buffer for Shapes


class VSyn {
 
    public:
        void setup();
        void update();
        void draw();
    
        shapeContainer shapes[CONTAINER_MAX];
        ofxOscReceiver receiver;
        int current_msg_string;
        string msg_strings[NUM_MSG_STRINGS];
        float timers[NUM_MSG_STRINGS];
    
        //CAMERA CONTROL
        ofEasyCam cam;
        bool cam_flg;
        ofVec3f pov;
        ofVec3f look;
    
    
    private:
        void initShapes(int max_num);
    
};

#endif /* VSyn_hpp */
