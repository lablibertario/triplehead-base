//
//  kfmPlayer.h
//  kfm
//
//  Created by Dewb on 10/22/14.
//
//

#ifndef __kfm__kfmPlayer__
#define __kfm__kfmPlayer__

#define NUM_PLAYERS 3
#define NUM_SCREENS 8

#define FRAME_RATE_MAX 90
#define FRAME_DELAY_MAX 24
#define FRAME_LOOP_MAX 30
#define FRAME_ADVANCE_MAX 5

#define FRAME_BUFFER_SIZE (FRAME_DELAY_MAX*(NUM_SCREENS-1) + FRAME_LOOP_MAX + FRAME_ADVANCE_MAX)

#define USE_SYPHON

#include "ofMain.h"
#include "ofxHapPlayer.h"

#ifdef USE_SYPHON
#include "ofxSyphonServer.h"
#endif


class kfmPlayer {
public:
    
    void init(string name);
    
    void update();
    void draw(int screen, int x, int y, int w, int h);
    ofFbo& getSingleScreen(int screen);
    void publishScreens();
    
    void initBuffer();
    void blankBuffer();
    void initNewMovie(std::string file);
    void bufferMovieFrames(int n);
    void jumpFrames(int n);
    
    
    void setDelay(int delay);
    void setLoop(int loop);
    void setAdvance(float advance);
    
protected:
    
    string name;
    bool _movieLoaded;
    
    int _nFrameDelay;
    int _nFrameLoop;
    float _fFrameAdvance;
    
    float _fFractionalAdvance;
    
    int _nCurrentFrame;
    int _nCurrentLoopStart;
    
    int _bufferCaret;
    vector<ofFbo> _buffer;
    ofVideoPlayer _player;
    
    
#ifdef USE_SYPHON
    ofxSyphonServer _syphonScreens[NUM_SCREENS];
#endif
    
};

#endif /* defined(__kfm__kfmPlayer__) */