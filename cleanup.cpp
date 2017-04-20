#include "game.h"

/**
* destroys used objects and frees any allocated memory
*/
void game::Cleanup(){
    SDL_DestroyTexture(tex);
    SDL_DestroyTexture(backg);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
