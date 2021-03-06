#pragma once

#include "ofMain.h"
#include "Node.h"
#include "OscReceiver.h"
//#include "airodumpEvents.h"
#include "airodumpGlobals.h"
#include "ofxUI.h"
#include "ofxTween.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void nodeAdded(AirodumpEventArgs& args);
    void nodeUpdated(AirodumpEventArgs& args);
    void nodeRemoved(AirodumpEventArgs& args);
    void guiEvent(ofxUIEventArgs& args);
    void updateIndices();
    void resetGrid();
    void addColorToGui(ofxUISuperCanvas* gui,string prefix,ofFloatColor& col, bool doAlpha = true);
    ofFloatColor getRGBfromHSV(ofFloatColor& hsv);
    
    map< ofFloatColor*, ofxUILabel*> labelColors;
	
    vector<Node> nodes;
    vector <int> activeNodes;
    vector<int> timeSortedIndices;
    OscReceiver receiver;
    map<string, int> clientMapIndex;
    map<string, int> routerMapIndex;
    vector<pair<int, int> > indexPairs;
    //        AirodumpEvents events;
    float maxPower, minPower;
    ofVec2f currentPos;
    int x,y;
    
    int numAliveRouters, numAliveClients;
    int currentMode;
    map<string, ofPoint>routerPos;
    map<string, ofPoint>clientPos;
    map<string,vector<int> > routerClientLinks;

    ofTrueTypeFont font;
    ofFloatColor fontColorHSV;

    ofxUISuperCanvas* gui;
    int routerX = 20;
    int routerY = 10;
    int routerWidth = 200;
    int routerHeight = 100;
    int clientX = 20;
    int clientY = 10;
    int clientWidth = 200;
    int clientHeight = 100;
    int maxDuration = 60;
    bool showDuration = true;
    bool showSSIDs = true;
    bool showESSIDs = true;
    bool showPower = false;


};
