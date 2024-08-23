#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 640;
    camHeight = 480;
    ofBackground(0, 0, 0);
    webcam.setVerbose(true);
    webcam.setup(camWidth, camHeight);
    font.load("Courier New Bold.ttf", 9);
    asciiChars =  string("  ..,,,'''``--_:;^^**""=+<>iv%&xclrs)/){}I?!][1taeo7zjLunT#@JCwfy325Fp6mqSghVd4EgXPGZbYkOA8U$KHDBWNMR0Q");
      
}

//--------------------------------------------------------------
void ofApp::update(){
    webcam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    videoTexture.draw( camWidth, 0, camWidth, camHeight);

    
    ofPixelsRef pixelsRef = webcam.getPixels();
    
    // chars are 7 pixels wide
    for (int i = 0; i < camWidth; i+= 7){
      //    // inside this is another loop that loops from 0 to the camHeight in steps of 9
        // chars are 9 pixels tall
      for (int j = 0; j < camHeight; j+= 9){
          // get the pixel and its lightness (lightness is the average of its RGB values)
          float lightness = pixelsRef.getColor(i,j).getLightness();

          // calculate the index of the character from our asciiCharacters array
          int character = powf( ofMap(lightness, 0, 255, 0, 1), 2.5) * asciiChars.size();

          // draw the character at the correct location
          font.drawString(ofToString(asciiChars[character]), i, j);
      }
  }

}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

