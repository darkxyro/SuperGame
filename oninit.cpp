#include "game.h"

using namespace std;



bool game::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        logSDLError(cout,"SDL_Init");
        return false;
    }
    if(TTF_Init()!=0){
        logSDLError(cout,"TTF_Init");
        return false;
    }
    if((window=SDL_CreateWindow("SuperGame",100,100,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN))==NULL){
        logSDLError(cout,"SDL_CreateWindow");
        return false;
    }
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(renderer==NULL){
        logSDLError(cout,"SDL_CreateRenderer");
        return false;
    }
    if((IMG_Init(IMG_INIT_PNG)&IMG_INIT_PNG)!=IMG_INIT_PNG){
        logSDLError(cout,"IMG_INIT");
        return false;
    }
    return LoadContent();
}
