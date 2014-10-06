#pragma once

#include "ofMain.h"
#include "ofxUI.h"

#ifdef USE_FENSTER
#include "ofxFenster.h"
#endif

#include "ofxOscReceiver.h"
#include "ofxSyphonServer.h"
#include "ofxHapPlayer.h"


class thbApp : public ofBaseApp {
public:
    thbApp();
    ~thbApp();
    
    void setup();
    void update();
    void draw();
    void drawProjectorOutput(int w, int h);
    
    void showProjectorWindow();
    void loadFile();
    
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseDragged(int x, int y, int button);
    void mouseMoved(int x, int y);

protected:
    void initGUI();
    void guiEvent(ofxUIEventArgs &e);
    
    void initBuffer();
    void blankBuffer();
    void initNewMovie(std::string file);
    void bufferMovieFrames(int n);
    void jumpFrames(int n);
    
    ofxUICanvas* _pUI;

#ifdef USE_FENSTER
    ofxFenster* _projectorWindow;
#endif
    
    bool _fullscreen;
    int _radioA;
    int _radioB;
    
    int _nFrameBufferSize;
    int _nFrameDelay;
    int _nFrameLoop;
    int _nFrameAdvance;
    
    int _nCurrentFrame;
    int _nCurrentLoopStart;
    
    int _nFrameCushion;
    
    float _fHeightPercent;
    float _fHeightOffset;
    int _nMargin;
    
    vector<string> _radioANames;
    vector<string> _radioBNames;
    
    int _bufferCaret;
    vector<ofFbo> _buffer;
    ofVideoPlayer _player;
    
    ofxOscReceiver _osc;
    
    ofFbo _syphonFrame;
    ofxSyphonServer _syphonServer;
};

#ifdef USE_FENSTER

class projectorWindowListener : public ofxFensterListener {
public:
    projectorWindowListener(thbApp* app);
    void setup();
    void draw();
protected:
    thbApp* _app;
};

#endif