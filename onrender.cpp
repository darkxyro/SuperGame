#include "game.h"

using namespace std;
/**
*standard render function called on every iteration
*@return true if successful, else false
*/
bool game::OnRender(){
    SDL_RenderClear(renderer);
    int xTiles=SCREEN_WIDTH/mTextures["grass"]->getWidth()+1;
    int yTiles=SCREEN_HEIGHT/mTextures["grass"]->getHeight()+1;
    for(int i=0;i<xTiles*yTiles;i++){
        int x=(i%xTiles)*mTextures["grass"]->getWidth();
        int y=(i/xTiles)*mTextures["grass"]->getHeight();
        mTextures["grass"]->render(renderer,x,y);
    }
    SDL_Color col={255,255,255,255};
    mTextures.emplace("fps",new WTexture);
    int fps=mFpsCounter.getFPS();
    string message="FPS: "+to_string(fps);
    if(mTextures["fps"]->loadFromText(renderer,message,col,16,STD_FONT)){
        mTextures["fps"]->render(renderer,SCREEN_WIDTH*3/4,SCREEN_HEIGHT/20);
    }
    mTextures.emplace("clock",new WTexture);
    string clock=mFpsCounter.getClockString();
    if(mTextures["clock"]->loadFromText(renderer,clock,col,16,STD_FONT)){
        mTextures["clock"]->render(renderer,SCREEN_WIDTH*1/4,SCREEN_HEIGHT*19/20);
    }
    SDL_RenderPresent(renderer);
    return true;
}



