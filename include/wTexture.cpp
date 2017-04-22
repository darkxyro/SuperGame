#include "wTexture.h"

using namespace std;

WTexture::WTexture(){
    mTexture=NULL;
    mWidth=0;
    mHeight=0;
}

WTexture::~WTexture(){
    free();
}

void WTexture::free(){
    SDL_DestroyTexture(mTexture);
    mTexture=NULL;
    mWidth=0;
    mHeight=0;
}

bool WTexture::loadTexture(SDL_Renderer* renderer,const string &file){
    free();
    mTexture=IMG_LoadTexture(renderer,file.c_str());
    if(mTexture==NULL){
        logSDLError(cout,"IMG_LoadTexture");
        return false;
    }
    SDL_QueryTexture(mTexture,NULL,NULL,&mWidth,&mHeight);
    return true;
}

void WTexture::render(SDL_Renderer* renderer,int x,int y,SDL_Rect* Clip){
    SDL_Rect rect={x,y,mWidth,mHeight};
    SDL_RenderCopy(renderer,mTexture,Clip,&rect);
}

void WTexture::render(SDL_Renderer* renderer,SDL_Rect* pos,SDL_Rect* Clip){
    SDL_RenderCopy(renderer,mTexture,Clip,pos);
}

int WTexture::getWidth(){
    return mWidth;
}

int WTexture::getHeight(){
    return mHeight;
}
