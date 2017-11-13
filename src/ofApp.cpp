#include "ofApp.h"

#define DATA    24    // orange
#define WR         25     // yellow
#define CS         18    // white
bool doMatrix = false;
bool doLED = false;
bool doStart = false;
void ofApp::onCharacterReceived(KeyListenerEventData& e)
{
    keyPressed((int)e.character);
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    consoleListener.setup(this);
    ofHideCursor();
    ledMatrix = NULL;
    wiringPiSetupGpio();
    ledMatrix = new LEDMatrix();
    
    vector<uint8_t>csPins;
    csPins.push_back(18);
    csPins.push_back(12);

    ledMatrix->setup(24, 25, csPins);
    ledMatrix->begin(HT1632_COMMON_16NMOS);
    
    ledMatrix->setTextSize(1);    // size 1 == 8 pixels high
    ledMatrix->setTextColor(1);   // 'lit' LEDs
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

string displayString="0";
//--------------------------------------------------------------
void ofApp::draw(){
    
    
    stringstream info;
    info << "width: " << (int)ledMatrix->width << endl;
    info << "height: " << (int)ledMatrix->height << endl;
    
    ofDrawBitmapStringHighlight(info.str(), 100, 100);
    
    if(doStart)
    {
        doStart = false;
        loop();
    }
        
}

void ofApp::loop() 
{
    
    ledMatrix->fillScreen();
    ledMatrix->writeScreen();
    ofSleepMillis(500);
    
    // blink!
    ledMatrix->blink(true);
    ofSleepMillis(2000);
    ledMatrix->blink(false);
    
    // Adjust the brightness down
    for (int8_t i=15; i>=0; i--) 
    {
        ledMatrix->setBrightness(i);
        ofSleepMillis(100);
    }
    // then back up
    for (uint8_t i=0; i<16; i++) 
    {
        ledMatrix->setBrightness(i);
        ofSleepMillis(100);
    }
    
    for (uint8_t y=0; y<ledMatrix->height; y++)
    {
        for (uint8_t x=0; x< ledMatrix->width; x++) 
        {
            ledMatrix->clrPixel(x, y);
            ledMatrix->writeScreen();
        }
    }
    
	return;
    
    for(uint8_t i=0; i<4; i++) 
    {
        //ledMatrix->setRotation(i);
        ledMatrix->clearScreen();
        ledMatrix->setCursor(0, 0);
        
        for (uint8_t y=0; y<ledMatrix->height; y++) 
        {
            for (uint8_t x=0; x< ledMatrix->width; x++) 
            {
                ofSleepMillis(100);
                ledMatrix->setPixel(x, y);
                ledMatrix->writeScreen();

            }
        }
    
        

      
        
        for (uint8_t y=0; y<ledMatrix->height; y++)
        {
            for (uint8_t x=0; x< ledMatrix->width; x++) 
            {
                ledMatrix->clrPixel(x, y);
                ledMatrix->writeScreen();
            }
        }
    }
}

void ofApp::exit()
{
    


    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofLog(OF_LOG_VERBOSE, "%c keyPressed", key);
    switch (key) 
    {
            
        case '1':
        {
            doLED = true;
            doMatrix = false;
            break;
        }
        case '2':
        {
            doMatrix = true;
            doLED = false;
            break;

        }
        case '0':
        {
            doStart = true;
            
        }
        default:
        {
            break;
        }    
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
