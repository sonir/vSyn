//
//  VSyn.cpp
//  vSyn
//
//  Created by sonir on 9/8/17.
//
//

#include "VSyn.hpp"

using namespace std;

void VSyn::setup(){
    
    ofBackground(0, 0, 0);
    ofSetCircleResolution(50);


    cout << "VSyn SETUP" << endl;
    receiver.setup(PORT);    
    current_msg_string = 0;
    
    //Init Shapes
    initShapes(CONTAINER_MAX);

}


void VSyn::update(){

    // hide old messages
    for(int i = 0; i < NUM_MSG_STRINGS; i++){
        if(timers[i] < ofGetElapsedTimef()){
            msg_strings[i] = "";
        }
    }
    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        // check for mouse moved message
        if(m.getAddress() == "/circle"){
            
            int uid =  m.getArgAsInt32(0);
            float x = m.getArgAsFloat(1);
            float y = m.getArgAsFloat(2);
            float size = m.getArgAsFloat(3);
            int fill = m.getArgAsInt32(4);
            
            if(uid < CONTAINER_MAX) // check the index is enable
            {
                toCircle(&shapes[uid] ,uid, x, y, size, fill);
            }
        } else if(m.getAddress() == "/triangle"){
            
            int uid =  m.getArgAsInt32(0);
            float x = m.getArgAsFloat(1);
            float y = m.getArgAsFloat(2);
            float size = m.getArgAsFloat(3);
            float angle = m.getArgAsFloat(4);
            int fill = m.getArgAsInt32(5);
            
            if(uid < CONTAINER_MAX) // check the index is enable
            {
                toTriangle(&shapes[uid] ,uid, x, y, size, angle, fill);
            }
        } else if(m.getAddress() == "/square"){
            
            int uid =  m.getArgAsInt32(0);
            float x = m.getArgAsFloat(1);
            float y = m.getArgAsFloat(2);
            float size = m.getArgAsFloat(3);
            float angle = m.getArgAsFloat(4);
            int fill = m.getArgAsInt32(5);
            
            if(uid < CONTAINER_MAX) // check the index is enable
            {
                toSquare(&shapes[uid] ,uid, x, y, size, angle, fill);
            }
        } else if(m.getAddress() == "/rect"){
            
            int uid =  m.getArgAsInt32(0);
            float x1 = m.getArgAsFloat(1);
            float y1 = m.getArgAsFloat(2);
            float x2 = m.getArgAsFloat(3);
            float y2 = m.getArgAsFloat(4);
            float angle = m.getArgAsFloat(5);
            int fill = m.getArgAsInt32(6);
            
            if(uid < CONTAINER_MAX) // check the index is enable
            {
                toRect(&shapes[uid] ,uid, x1, y1, x2, y2, angle, fill);
            }
        } else if(m.getAddress() == "/line"){
            
            int uid =  m.getArgAsInt32(0);
            float x1 = m.getArgAsFloat(1);
            float y1 = m.getArgAsFloat(2);
            float x2 = m.getArgAsFloat(3);
            float y2 = m.getArgAsFloat(4);
            float thick = m.getArgAsFloat(5);
            
            if(uid < CONTAINER_MAX) // check the index is enable
            {
                toLine(&shapes[uid] ,uid, x1, y1, x2, y2, thick);
            }
        } else if(m.getAddress() == "/arc"){
            
            int uid =  m.getArgAsInt32(0);
            float x1 = m.getArgAsFloat(1);
            float y1 = m.getArgAsFloat(2);
            float x2 = m.getArgAsFloat(3);
            float y2 = m.getArgAsFloat(4);
            float height = m.getArgAsFloat(5);
            float thick = m.getArgAsFloat(6);
            
            if(uid < CONTAINER_MAX) // check the index is enable
            {
                toArc(&shapes[uid] ,uid, x1, y1, x2, y2, height, thick);
            }
        } else if(m.getAddress() == "/wave"){
            
            int uid =  m.getArgAsInt32(0);
            
            float x1 = m.getArgAsFloat(1);
            float y1 = m.getArgAsFloat(2);
            float x2 = m.getArgAsFloat(3);
            float y2 = m.getArgAsFloat(4);
            float freq = m.getArgAsFloat(5);
            float amp = m.getArgAsFloat(6);
            float phase = m.getArgAsFloat(7);
            float thick = m.getArgAsFloat(8);
            
            if(uid < CONTAINER_MAX) // check the index is enable
            {
                toWave(&shapes[uid] ,uid, x1, y1, x2, y2, freq, amp, phase, thick);
            }
            
        } else if(m.getAddress() == "/mute"){
            
            int uid =  m.getArgAsInt32(0);
            
            if(uid < CONTAINER_MAX) // check the index is enable
            {
                toMute(&shapes[uid]);
            }
            
        } else {
            
            cout << "OSC :: unknown ADR :: " << m.getAddress() << endl;
            
        }
        
        
        
        
        
   
    }
    


}


void VSyn::initShapes(int max_num){

    for(int i=0; i<max_num; i++){

        shapeContainer *pC = &shapes[i];
        pC->active = false;
        pC->uid = -1;
        
        pC->x1 = 0.5f;
        pC->y1 = 0.5f;
        pC->x2 = 0.5f;
        pC->y2 = 0.5f;
        
        pC->size = 0.0f;
        pC->height = 0.0f;
        pC->angle = 0.0f;
        pC->freq = 0.0f;
        pC->amp = 0.0f;
        pC->phase = 0.0f;
        pC->thick = 0.0f;
        
        pC->fill = false;

        
    }

}



void VSyn::draw(){
 
    ofSetColor(255, 255, 255);
//    circle(x, y, 0.2, 1);

    for(int i=0; i<CONTAINER_MAX; i++){
        
        shapeContainer *elm = &shapes[i];
        
        
        if ( !elm->active ){
            
            continue;
            
        }
        
        switch(elm->type){
                
            case CIRCLE:
                circle(elm->x1, elm->y1, elm->size, elm->fill);
                break;
                
            case TRIANGLE:
                triangle(elm->x1, elm->y1, elm->size, elm->angle, elm->fill);
                break;

            case SQUARE:
                square(elm->x1, elm->y1, elm->size, elm->angle, elm->fill);
                break;

            case RECT:
                rect(elm->x1, elm->y1, elm->x2, elm->y2, elm->angle, elm->fill);
                break;

            case LINE:
                line(elm->x1, elm->y1, elm->x2, elm->y2, elm->thick);
                break;

            case ARC:
                arc(elm->x1, elm->y1, elm->x2, elm->y2, elm->height, elm->thick);
                break;

            case WAVE:
                wave(elm->x1, elm->y1, elm->x2, elm->y2, elm->freq, elm->amp, elm->phase, elm->thick);
                break;
                
            default:
                break;
                
        }
        
        
    }
    
}
