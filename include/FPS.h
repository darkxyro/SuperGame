#ifndef FPS_H_INCLUDED
#define FPS_H_INCLUDED

#include "../includes.h"

class FPSCounter{
    private:
        unsigned long mFrametime;
        int mFramerate[60];
        int mFrameratePointer;
        int FPS;
    public:
        FPSCounter();
        ~FPSCounter();
        int getFPS();
        unsigned long getLastFrameTime();
        void setNewFrameTime(unsigned long time);

};

#endif // FPS_H_INCLUDED
