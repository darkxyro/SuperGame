#include "game.h"

using namespace std;



void game::Cleanup(){
    for(auto it=mTextures.begin();it!=mTextures.end();++it){
        it->second->free();
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
