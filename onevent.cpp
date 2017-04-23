#include "game.h"

using namespace std;

void game::OnEvent(SDL_Event* Event){
    switch(Event->type){
    case SDL_KEYDOWN:
        switch(Event->key.keysym.sym){
        case SDLK_ESCAPE:
            Running=false;
            break;
        case SDLK_UP:
            break;
        case SDLK_RIGHT:
            break;
        case SDLK_DOWN:
            break;
        case SDLK_LEFT:
            break;
        case SDLK_p:
            mPaused=!mPaused;
            break;
        }
        break;
    case SDL_QUIT:
        Running=false;
        break;
    }
}
