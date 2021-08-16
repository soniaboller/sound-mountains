#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    gui.setup();
//    gui.add(amp.setup("amp", 400, 1, 500));
//    gui.add(freq.setup("freq", 10, 1, 100));
//    gui.add(phase.setup("phase", 10, 1, 100));
    
    // load in sounds:
    mp3.load("sounds/beardance.mp3");
    
    // the fft needs to be smoothed out, so we create an array of floats
    // for that purpose:
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    
//    nBandsToGet = 64;
//    nBandsToGet = 128;
    nBandsToGet = 256;
//    nBandsToGet = 512;
    

    mp3.play();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    float * val = ofSoundGetSpectrum(nBandsToGet);
    for (int i = 0;i < nBandsToGet; i++){
        
        // let the smoothed calue sink to zero:
        fftSmoothed[i] *= 0.96f;
        
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.draw();
    
//    cam.begin();
    
    ofSetBackgroundColor(255);
    
//    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    mesh.setMode(OF_PRIMITIVE_POINTS);
//    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    
    float time = ofGetElapsedTimef() /10;
    
    for (int i = 0;i < nBandsToGet; i++){
        float x = 0;
        float y = 0;
//        float a = ofMap(i, 0, 100, 0, 2 * PI);
//        float r = 250;
//        float x = r * cos(a) - spiral;
//        float y = r * sin(a) - spiral;
        mesh.addVertex(ofVec3f(xPosition, yPosition + -(fftSmoothed[i] * 15), 0));
        mesh.addColor(ofColor(0));
//        mesh.addColor(ofColor(
//                              255 * ofNoise(x / 100, y / 100, ofGetElapsedTimef(), 100),
//                              255 * ofNoise(x / 100, y / 100, ofGetElapsedTimef(), 200),
//                              255 * ofNoise(x / 100, y / 100, ofGetElapsedTimef(), 300)
//                              ));
    }
    
    mesh.draw();
    
    for (int i = 0; i < meshes.size(); i++) {
        meshes[i].draw();
    }
    
    xPosition +=1;
    
    if(xPosition > ofGetWidth()){
        meshes.push_back(mesh);
        xPosition = 0;
        yPosition += 100;
        mesh.clear();
    }
    
//    cam.end();
    
    
//    ofNode -- has point in space
//    quaterian 
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout << key << endl;
    if(key == 'x'){
        img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
        img.save(ofGetTimestampString(), OF_IMAGE_QUALITY_BEST);
    }
   
    
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
