#pragma once

#include "ofMain.h"
#include "opencv2/opencv.hpp"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    float capW;
    float capH;

    
    ofVideoGrabber grabber;
    ofxCvColorImage frameImage;
    
    cv::Mat edgeImage;
    cv::Mat frame;
};

