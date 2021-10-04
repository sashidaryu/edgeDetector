#include "ofApp.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/utility.hpp"
#include "ofxCv.h"
#include "ofxOpenCv.h"

void ofApp::setup(){
    grabber.setup(480, 640, OF_PIXELS_BGRA);
    ofSetFrameRate(10);
    capW = grabber.getWidth();
    capH = grabber.getHeight();
}

void ofApp::update() {
    grabber.update();
    frameImage.setFromPixels(grabber.getPixels().getData(), capW, capH);
    frame = ofxCv::toCv(frameImage);
    if(grabber.isFrameNew()){
        cv::Canny(frame, this->edgeImage, 50, 150);
    }
}

void ofApp::draw() {
    ofxCv::drawMat(edgeImage, 0, 0);
}
