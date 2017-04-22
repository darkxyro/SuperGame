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
            useClip=0;
            break;
        case SDLK_RIGHT:
            useClip=1;
            break;
        case SDLK_DOWN:
            useClip=2;
            break;
        case SDLK_LEFT:
            useClip=3;
            break;
        }
        break;
    case SDL_QUIT:
        Running=false;
        break;
    }
}
