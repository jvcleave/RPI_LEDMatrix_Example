#pragma once

#include "ofMain.h"
#include "ofxHT1632Matrix.h"
#include "TerminalListener.h"

class ofApp : public ofBaseApp, public KeyListener
{
	public:
		
    TerminalListener consoleListener;
    ofxHT1632Matrix* ledMatrix;

    bool doStart = false;
    ofImage image;
    bool doFBO = false;
    
    void setup()
    {
        //ofSetVerticalSync(false);
        //ofSetFrameRate(10);
        ofSetLogLevel(OF_LOG_VERBOSE);
        consoleListener.setup(this);
        ofHideCursor();
        ledMatrix = new ofxHT1632Matrix();
        ledMatrix->setup();
     
        image.load("of.png");
    }
    
    void update()
    {
        
    }
    
    void draw()
    {
        
        if(doStart)
        {
            doStart = false;
            ledMatrix->testLoop();
        }
        if(doFBO)
        {

            
            ledMatrix->drawImage(image);
            doFBO = false;
        }
        
        image.draw(image.getWidth(), image.getHeight());

        //ofDrawBitmapStringHighlight(ledMatrix->getInfo(), 100, 100);

    }
    
    void keyPressed(int key)
    {
        ofLog(OF_LOG_VERBOSE, "%c keyPressed", key);
        switch (key) 
        {
                
            case '1':
            {
                doFBO = true;
                break;
            }
            case '2':
            {
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
    
    void onCharacterReceived(KeyListenerEventData& e)
    {
        keyPressed((int)e.character);
    }
    
};
