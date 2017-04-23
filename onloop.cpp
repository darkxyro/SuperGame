#include "game.h"

using namespace std;


bool game::OnLoop(){
    updateCamera();
    if(!mPaused){
        mFpsCounter.updateClock();
    }
    return true;
}


void game::updateCamera(){
    const Uint8* keyStates=SDL_GetKeyboardState(NULL);
    if(keyStates[SDL_SCANCODE_UP]){
        Camera.y-=CAMERA_SPEED;
        if(Camera.y<0)
            Camera.y=0;
    }
    if(keyStates[SDL_SCANCODE_DOWN]){
        Camera.y+=CAMERA_SPEED;
        if(Camera.y>MAP_HEIGHT-SCREEN_HEIGHT)
            Camera.y=MAP_HEIGHT-SCREEN_HEIGHT;
    }
    if(keyStates[SDL_SCANCODE_LEFT]){
        Camera.x-=CAMERA_SPEED;
        if(Camera.x<0)
            Camera.x=0;
    }
    if(keyStates[SDL_SCANCODE_RIGHT]){
        Camera.x+=CAMERA_SPEED;
        if(Camera.x>MAP_WIDTH-SCREEN_WIDTH)
            Camera.x=MAP_WIDTH-SCREEN_WIDTH;
    }
}
