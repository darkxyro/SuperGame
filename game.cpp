#include "game.h"

using namespace std;

game::game(){
    window=NULL;
    Running=true;
    useClip=0;
    mPaused=false;
    Camera={0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
}



int game::OnExecute(){
    if(OnInit()==false){
        return -1;
    }
    while(Running){
        mFpsCounter.setNewFrameTime(SDL_GetTicks());
        while(SDL_PollEvent(&Event)){
            OnEvent(&Event);
        }
        if(!OnLoop())
            Running=false;
        if(!OnRender())
            Running=false;
        if(1000/(SDL_GetTicks()-mFpsCounter.getLastFrameTime())>MAX_FPS)
            SDL_Delay((1000/MAX_FPS)+mFpsCounter.getLastFrameTime()-SDL_GetTicks());
    }
    Cleanup();
    return 0;
}



int main(int argc, char* argv[]){
    game SuperGame;
    return SuperGame.OnExecute();
}
