//
//  drawer.cpp
//
//  Created by Hana on 2017/09/08.
//
//


#include "drawer.hpp"


void circle(float x, float y, float size, int fill) {
    int width = ofGetWidth();
    int height = ofGetHeight();
    
    if(fill == 1) {
        ofFill();
    } else {
        ofNoFill();
        ofSetLineWidth(2.0);
    }
    
    int radius = size * width;
    ofDrawCircle(x * width, y * height, radius);
}


void triangle(float x, float y, float size, float angle, int fill) {
    int width = ofGetWidth();
    int height = ofGetHeight();
    
    //Ready Variables
    ofVec2f center, normalizedTop, normalizedLeft, normalizedRight;
    double root3 = sqrt(3.0);
    float scaledSize = width * size;
    
    center.set(x * width, y * height);
    normalizedTop.set(0, -root3 / 3);
    normalizedLeft.set(-0.5, root3 / 6);
    normalizedRight.set(0.5, root3 / 6);
    
    ofVec2f top = normalizedTop * scaledSize;
    ofVec2f left = normalizedLeft * scaledSize;
    ofVec2f right = normalizedRight * scaledSize;
    
    
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
    
    int width = ofGetWidth();
    int height = ofGetHeight();
    
    //Fill Setting
    if(fill == 1) {
        ofFill();
    } else {
        ofNoFill();
        ofSetLineWidth(2.0);
    }
    
    //Draw
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(x * width, y * height);
    ofRotate(360 * angle);
    ofDrawRectangle(0, 0, size * width, size * width);
    ofPopMatrix();
}

void rect(float x1, float y1, float x2, float y2, float angle, int fill) {
    int width = ofGetWidth();
    int height = ofGetHeight();
    
    //Fill Setting
    if(fill == 1) {
        ofFill();
    } else {
        ofNoFill();
        ofSetLineWidth(2.0);
    }
    
    //Culcurate Position and Dimension
    float centerX = width *(x1 + x2) / 2;
    float centerY = height *(y1 + y2) / 2;
    float rectWidth = width * abs(x1 - x2) ;
    float rectHeight = height * abs(y1 - y2);
    
    //Draw
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(centerX, centerY);
    ofRotate(360 * angle);
    ofDrawRectangle(0, 0, rectWidth, rectHeight);
    ofPopMatrix();
}

void line(float x1, float y1, float x2, float y2, float thick) {
    int width = ofGetWidth();
    int height = ofGetHeight();
    
    ofSetLineWidth(thick);
    ofDrawLine(width * x1, height * y1, width * x2, height * y2);
}

void arc(float x1, float y1, float x2, float y2, float arcHeight,  float thick) {
    int width = ofGetWidth();
    int height = ofGetHeight();
    
    //Get Line status
    ofVec2f start = ofVec2f(x1 * width, y1 * height);
    ofVec2f end = ofVec2f(x2 * width, y2 * height);
    ofVec2f line = end - start;
    
    int length = line.length();
    float angle = line.getNormalized().angle(ofVec2f(1,0));
    
    //Draw
    float division = 100.0;
    ofSetLineWidth(thick);
    
    ofVec2f currentPointOnLine = ofVec2f(0, 0);
    ofVec2f currentPos = ofVec2f(0, 0);
    ofVec2f previousPos = start;
    
    for (int i = 0; i < division; i++) {
        currentPointOnLine = line * i / division + start;
        currentPos = currentPointOnLine + line.getNormalized().rotate(-90) * sin(i/division * PI) * width * arcHeight;
        ofDrawLine(previousPos, currentPos);
        previousPos = currentPos;
    }
}

void wave(float x1, float y1, float x2, float y2, float freq, float amplitude, float phase, float thick) {
    int width = ofGetWidth();
    int height = ofGetHeight();
    
    //Culcurate Line status
    ofVec2f start = ofVec2f(x1 * width, y1 * height);
    ofVec2f end = ofVec2f(x2 * width, y2 * height);
    ofVec2f line = end - start;
    
    int length = line.length();
    float angle = line.getNormalized().angle(ofVec2f(1,0));
    
    float division = 200.0;
    ofSetLineWidth(thick);
    
    //Draw
    ofVec2f currentPointOnLine = ofVec2f(0, 0);
    ofVec2f currentPos = ofVec2f(0, 0);
    ofVec2f previousPos = ofVec2f(0, 0);
    
    for (int i = 0; i < division; i++) {
        if (i == 0) {
            currentPointOnLine = line * i / division + start;
            previousPos = currentPointOnLine + line.getNormalized().rotate(90) * sin((i/division * PI * 2 * freq) + (phase * 2 * PI)) * width * amplitude;
        }
        currentPointOnLine = line * i / division + start;
        currentPos = currentPointOnLine + line.getNormalized().rotate(90) * sin((i/division * PI * 2 * freq) + (phase * 2 * PI)) * width * amplitude;
        ofDrawLine(previousPos, currentPos);
        previousPos = currentPos;
    }
    
}

    






















