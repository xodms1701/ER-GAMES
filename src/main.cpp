#include "ofMain.h"
#include "ofApp.h"


//========================================================================
int main() {	
	ofGLFWWindowSettings settings;
	settings.width = 1920;    // â ���� ������
	settings.height = 1080;  // â ���� ������
	//settings.windowMode = OF_WINDOW;
	settings.decorated = false;     // <---------- �� �κ��� �߿�
	ofCreateWindow(settings);
	//ofSetupOpenGL(2560,1080,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN-
	// pass in width and height too:
	ofRunApp(new ofApp());
}