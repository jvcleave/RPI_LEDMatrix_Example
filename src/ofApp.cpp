#include "ofApp.h"

#define DATA    24    // orange
#define WR         25     // yellow
#define CS         18    // white
bool doMatrix = false;
bool doLED = false;

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
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(doLED)
    {
        doLED = false;
        blink();
    }else
    {
        if(doMatrix)
        {
            doMatrix = false;
            if(!ledMatrix)
            {
                ledMatrix = new HT1632LEDMatrix();
                ledMatrix->setup(24, 25, 18);
                ledMatrix->begin(HT1632_COMMON_16NMOS);
                ledMatrix->clearScreen();
                ofSleepMillis(2000);

                ledMatrix->fillScreen();
                ofSleepMillis(2000);

                ledMatrix->writeScreen();
                ofSleepMillis(2000);

                ledMatrix->clearScreen();

            }
            /*
            ledMatrix->setTextSize(1);    // size 1 == 8 pixels high
            ledMatrix->setTextColor(1);   // 'lit' LEDs
            
            ledMatrix->setCursor(0, 0);   // start at top left, with one pixel of spacing
            ledMatrix->print("PLAY");
            ledMatrix->writeScreen();
            
            int i = 0;
            for (i = 0; i < 4; ++i) {
                ofSleepMillis(500);
                
                ledMatrix->clearScreen();
                ledMatrix->setCursor(0, 0);   // start at top left, with one pixel of spacing
                ledMatrix->print("PLAY");
                ledMatrix->setCursor(0, 8);   // next line, 8 pixels down
                ledMatrix->print("PONG");
                ledMatrix->writeScreen();
                
                ofSleepMillis(500);
                
                
                ledMatrix->clearScreen();
                ledMatrix->setCursor(0, 0);   // start at top left, with one pixel of spacing
                ledMatrix->print("PLAY");
                ledMatrix->writeScreen();
            }
            
            ofSleepMillis(500);
            
            
            ledMatrix->clearScreen();
            ledMatrix->setCursor(0, 0);   // start at top left, with one pixel of spacing
            ledMatrix->print("PLAY");
            ledMatrix->setCursor(0, 8);   // next line, 8 pixels down
            ledMatrix->print("PONG");
            ledMatrix->writeScreen();
            */
            ofLog() << "didIntro";
            
            
        }
        
    }
}
void ofApp::blink()
{
    ofLog() << "blink";
    
    pinMode (0, OUTPUT) ;
    for (int i=0; i<100; i++)
    {
        digitalWrite (0, HIGH); 
        delay (500) ;
        digitalWrite (0,  LOW);
        delay (500);
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
   
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
