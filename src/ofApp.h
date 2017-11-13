#pragma once

#include "ofMain.h"
#include "LEDPanel.h"
#include "TerminalListener.h"

class ofApp : public ofBaseApp, public KeyListener{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void exit();

    LEDMatrix* ledMatrix;
    //allows key commands via Shell
    void onCharacterReceived(KeyListenerEventData& e);
    TerminalListener consoleListener;
    
    void loop();
};
