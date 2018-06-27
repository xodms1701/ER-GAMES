#include "ofMain.h"
#include "ofApp.h"


//========================================================================
int main() {	
	ofGLFWWindowSettings settings;
	settings.width = 1920;    // 창 가로 사이즈
	settings.height = 1080;  // 창 세로 사이즈
	//settings.windowMode = OF_WINDOW;
	settings.decorated = false;     // <---------- 요 부분이 중요
	ofCreateWindow(settings);
	//ofSetupOpenGL(2560,1080,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN-
	// pass in width and height too:
	ofRunApp(new ofApp());
}