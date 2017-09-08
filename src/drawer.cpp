//
//  drawer.cpp
//
//  Created by Hana on 2017/09/08.
//
//

#include "drawer.hpp"

void circle(float x, float y, float size, int fill) {
    ofSetColor(255);
    if(fill == 1) {
        ofFill();
    } else {
        ofNoFill();
        ofSetLineWidth(2.0);
    }
    
    int radius = size * ofGetWidth();
    ofDrawCircle(x * ofGetWidth(), y * ofGetHeight(), radius);
}


void triangle(float x, float y, float size, float angle, int fill) {
    ofVec2f center, normalizedTop, normalizedLeft, normalizedRight;
    double root3 = sqrt(3.0);
    float scaledSize = ofGetWidth() * size;
    
    center.set(x * ofGetWidth(), y * ofGetHeight());
    normalizedTop.set(0, -root3 / 3);
    normalizedLeft.set(-0.5, root3 / 6);
    normalizedRight.set(0.5, root3 / 6);
    
    ofVec2f top = normalizedTop * scaledSize;
    ofVec2f left = normalizedLeft * scaledSize;
    ofVec2f right = normalizedRight * scaledSize;
    
    
    ofSetColor(255);
    if(fill == 1) {
        ofFill();
    } else {
        ofNoFill();
        ofSetLineWidth(2.0);
    }
    
    
    ofPushMatrix();
    ofTranslate(center);
    ofRotate(360 * angle);
    ofDrawTriangle(top, left, right);
    ofPopMatrix();
}



void square(float x, float y, float size, float angle, int fill) {
    ofSetColor(255);
    if(fill == 1) {
        ofFill();
    } else {
        ofNoFill();
        ofSetLineWidth(2.0);
    }
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(x * ofGetWidth(), y * ofGetHeight());
    ofRotate(360 * angle);
    ofDrawRectangle(0, 0, size * ofGetWidth(), size * ofGetWidth());
    ofPopMatrix();
}

void rect(float x1, float y1, float x2, float y2, float angle, int fill) {
    ofSetColor(255);
    if(fill == 1) {
        ofFill();
    } else {
        ofNoFill();
        ofSetLineWidth(2.0);
    }
    
    float centerX = ofGetWidth() *(x1 + x2) / 2;
    float centerY = ofGetHeight() *(y1 + y2) / 2;
    float width = ofGetWidth() * abs(x1 - x2) ;
    float height = ofGetHeight() * abs(y1 - y2);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(centerX, centerY);
    ofRotate(360 * angle);
    ofDrawRectangle(0, 0, width, height);
    ofPopMatrix();
}

void line(float x1, float y1, float x2, float y2, float thick) {
    ofSetLineWidth(thick);
    ofDrawLine(ofGetWidth() * x1, ofGetHeight() * y1, ofGetWidth() * x2, ofGetHeight() * y2);
}


void arc(float x1, float y1, float x2, float y2, float height, int direction, float thick) {
    ofSetColor(255);
    
    //Culcurate Line status
    ofVec2f start = ofVec2f(x1 * ofGetWidth(), y1 * ofGetHeight());
    ofVec2f end = ofVec2f(x2 * ofGetWidth(), y2 * ofGetHeight());
    ofVec2f line = end - start;
    
    int length = line.length();
    float angle = line.getNormalized().angle(ofVec2f(1,0));
    
    float division = 100.0;
    ofSetLineWidth(thick);
    
    ofVec2f currentPointOnLine = ofVec2f(0, 0);
    ofVec2f currentPos = ofVec2f(0, 0);
    ofVec2f previousPos = start;
    
    for (int i = 0; i < division; i++) {
        currentPointOnLine = line * i / division + start;
        currentPos = currentPointOnLine + line.getNormalized().rotate(90 * direction) * sin(i/division * PI) *ofGetWidth() * height;
        ofDrawLine(previousPos, currentPos);
        previousPos = currentPos;
    }
}


void wave(float x1, float y1, float x2, float y2, float freq, float amplitude,float phase, float thick) {
    ofSetColor(255);
    
    //Culcurate Line status
    ofVec2f start = ofVec2f(x1 * ofGetWidth(), y1 * ofGetHeight());
    ofVec2f end = ofVec2f(x2 * ofGetWidth(), y2 * ofGetHeight());
    ofVec2f line = end - start;
    
    int length = line.length();
    float angle = line.getNormalized().angle(ofVec2f(1,0));
    
    float division = 200.0;
    ofSetLineWidth(thick);
    
    ofVec2f currentPointOnLine = ofVec2f(0, 0);
    ofVec2f currentPos = ofVec2f(0, 0);
    ofVec2f previousPos = ofVec2f(0, 0);
    
    for (int i = 0; i < division; i++) {
        if (i == 0) {
            currentPointOnLine = line * i / division + start;
            previousPos = currentPointOnLine + line.getNormalized().rotate(90) * sin((i/division * PI * 2 * freq) + (phase * 2 * PI)) * ofGetWidth() * amplitude;
        }
        currentPointOnLine = line * i / division + start;
        currentPos = currentPointOnLine + line.getNormalized().rotate(90) * sin((i/division * PI * 2 * freq) + (phase * 2 * PI)) * ofGetWidth() * amplitude;
        ofDrawLine(previousPos, currentPos);
        previousPos = currentPos;
    }
    
}

    





















