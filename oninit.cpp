#include "game.h"


/**
*initializes the program, calls LoadContent at the end
*@return true if successful, else false
*/
bool game::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        logSDLError(cout,"SDL_Init");
        return false;
    }
    if((window=SDL_CreateWindow("SuperGame",100,100,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN))==NULL){
        logSDLError(cout,"SDL_CreateWindow");
        return false;
    }
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(renderer==NULL){
        logSDLError(cout,"SDL_CreateRenderer");
        return false;
    }
    return LoadContent();
}
