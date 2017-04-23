#ifndef FPS_H_INCLUDED
#define FPS_H_INCLUDED

#include "../includes.h"

class FPSCounter{
    private:
        unsigned long mFrametime;
        unsigned long mPrevFrametime;
        int mFramerate[60];
        int mFrameratePointer;
        int FPS;
        int mMilseconds;
        int mSeconds;
        int mMinutes;
    public:
        FPSCounter();
        ~FPSCounter();
        int getFPS();
        unsigned long getLastFrameTime();
        void setNewFrameTime(unsigned long time);
        void updateClock();
        std::string getClockString();

};

#endif // FPS_H_INCLUDED
