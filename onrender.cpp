#include "game.h"

/**
*standard render function called on every iteration
*@return true if successful, else false
*/
bool game::OnRender(){
    SDL_RenderClear(renderer);
    int pW,pH;
    SDL_QueryTexture(backg,NULL,NULL,&pW,&pH);
    for(int i=0;i<(SCREEN_WIDTH/pW);i++){
        for(int j=0;j<(SCREEN_HEIGHT/pH);j++){
            renderTexture(backg, renderer,i*pW,j*pH);
        }
    }
    SDL_QueryTexture(tex,NULL,NULL,&pW,&pH);
    int x=(SCREEN_WIDTH-pW)/2;
    int y=(SCREEN_HEIGHT-pH)/2;
    renderTexture(tex,renderer,x,y);
    SDL_RenderPresent(renderer);
    return true;
}



void game::renderTexture(SDL_Texture* tex,SDL_Renderer* ren,int x,int y){
    SDL_Rect dst;
    dst.x=x;
    dst.y=y;
    SDL_QueryTexture(tex,NULL,NULL,&dst.w,&dst.h);
    SDL_RenderCopy(ren,tex,NULL,&dst);
}
