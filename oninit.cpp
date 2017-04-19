#include "game.h"

bool game::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        return false;
    }
    if((window=SDL_CreateWindow("SuperGame",100,100,640,480,SDL_WINDOWEVENT_SHOWN))==NULL){
        return false;
    }
    renderer=SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(renderer==NULL){
        cout<<SDL_GetError()<<endl;
        return false;
    }
    return true;
}
