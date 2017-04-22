#include "FPS.h"

using namespace std;


FPSCounter::FPSCounter(){
    mFrametime=0;
    mFrameratePointer=0;
    FPS=0;
    for(int i=0;i<60;i++){
        mFramerate[i]=60;
    }
}

FPSCounter::~FPSCounter(){}


void FPSCounter::setNewFrameTime(unsigned long frameTime){
    int currentFPS=1000/(frameTime-mFrametime);
    mFramerate[mFrameratePointer]=currentFPS;
    mFrameratePointer++;
    if(mFrameratePointer>=60)
        mFrameratePointer=0;
    mFrametime=frameTime;

}


unsigned long FPSCounter::getLastFrameTime(){
    return mFrametime;
}

int FPSCounter::getFPS(){
    FPS=0;
    for(int i=0;i<60;i++){
        FPS+=mFramerate[i];
    }
    FPS=FPS/60;
    return FPS;
}
