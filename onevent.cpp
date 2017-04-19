#include "game.h"

void game::OnEvent(SDL_Event* Event){
    switch(Event->type){
    case SDL_KEYDOWN:
        if(Event->key.keysym.sym!=SDLK_ESCAPE)
            break;
    case SDL_QUIT:
        Running=false;
        break;
    }
}
