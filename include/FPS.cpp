#include "FPS.h"

using namespace std;


FPSCounter::FPSCounter(){
    mFrametime=0;
    mPrevFrametime=0;
    mFrameratePointer=0;
    FPS=0;
    mMilseconds=0;
    mSeconds=0;
    mMinutes=0;
    for(int i=0;i<60;i++){
        mFramerate[i]=60;
    }
}

FPSCounter::~FPSCounter(){}


void FPSCounter::updateClock(){
    mMilseconds+=(mFrametime-mPrevFrametime);
    if(mMilseconds>=1000){
        mMilseconds-=1000;
        mSeconds+=1;
    }
    if(mSeconds>=60){
        mSeconds-=60;
        mMinutes+=1;
    }
}

string FPSCounter::getClockString(){
    string clock=to_string(mMinutes)+":";
    if(mSeconds<10)
        clock+="0";
    clock+=to_string(mSeconds);
    return clock;
}

void FPSCounter::setNewFrameTime(unsigned long frameTime){
    int currentFPS=1000/(frameTime-mFrametime);
    mFramerate[mFrameratePointer]=currentFPS;
    mFrameratePointer++;
    if(mFrameratePointer>=60)
        mFrameratePointer=0;
    mPrevFrametime=mFrametime;
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
