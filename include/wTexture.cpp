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


bool WTexture::loadFromText(SDL_Renderer* renderer,const string message,SDL_Color col,int fontSize,const string fontFileName){
    free();
    string fontPath=getResourcePath()+fontFileName;
    TTF_Font* font=TTF_OpenFont(fontPath.c_str(),fontSize);
    if (font==NULL){
        logSDLError(cout,"TTF_OpenFont");
        return false;
    }
	SDL_Surface* surf=TTF_RenderText_Blended(font,message.c_str(),col);
	if (surf==NULL){
		TTF_CloseFont(font);
		logSDLError(cout, "TTF_RenderText");
		return false;
	}
	mTexture=SDL_CreateTextureFromSurface(renderer,surf);
	if (mTexture==NULL){
		logSDLError(cout, "CreateTexture");
	}
	else{
        mWidth=surf->w;
        mHeight=surf->h;
	}
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return mTexture!=NULL;
}

bool WTexture::loadFromText(SDL_Renderer* renderer,string message,SDL_Color col,TTF_Font* font){
    free();
	SDL_Surface* surf=TTF_RenderText_Blended(font,message.c_str(),col);
	if (surf==NULL){
		TTF_CloseFont(font);
		logSDLError(cout, "TTF_RenderText");
		return false;
	}
	mTexture=SDL_CreateTextureFromSurface(renderer,surf);
	if (mTexture==NULL){
		logSDLError(cout, "CreateTexture");
	}
	else{
        mWidth=surf->w;
        mHeight=surf->h;
	}
	SDL_FreeSurface(surf);
	return mTexture!=NULL;
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

void WTexture::render(SDL_Renderer* renderer,int x,int y,SDL_Rect* Camera,SDL_Rect* Clip,double angle,SDL_Point* center,SDL_RendererFlip flip){
    SDL_Rect pos={x,y,mWidth,mHeight};
    bool render=true;
    if(Camera!=NULL){
        if((pos.x<Camera->x)&&(pos.x+pos.w<Camera->x))
            render=false;
        if((pos.x>Camera->x+Camera->w)&&(pos.x+pos.w>Camera->x+Camera->w))
            render=false;
        if((pos.y<Camera->y)&&(pos.y+pos.h<Camera->y))
            render=false;
        if((pos.y>Camera->y+Camera->h)&&(pos.y+pos.h>Camera->y+Camera->h))
            render=false;
        pos.x-=Camera->x;
        pos.y-=Camera->y;
    }
    if(render)
        SDL_RenderCopyEx(renderer,mTexture,Clip,&pos,angle,center,flip);
}

void WTexture::render(SDL_Renderer* renderer,SDL_Rect* pos,SDL_Rect* Camera,SDL_Rect* Clip,double angle,SDL_Point* center,SDL_RendererFlip flip){
    bool render=true;
    if(Camera!=NULL){
        if((pos->x<Camera->x)&&(pos->x+pos->w<Camera->x))
            render=false;
        if((pos->x>Camera->x+Camera->w)&&(pos->x+pos->w>Camera->x+Camera->w))
            render=false;
        if((pos->y<Camera->y)&&(pos->y+pos->h<Camera->y))
            render=false;
        if((pos->y>Camera->y+Camera->h)&&(pos->y+pos->h>Camera->y+Camera->h))
            render=false;
        pos->x-=Camera->x;
        pos->y-=Camera->y;
    }
    if(render)
        SDL_RenderCopyEx(renderer,mTexture,Clip,pos,angle,center,flip);
}

int WTexture::getWidth(){
    return mWidth;
}

int WTexture::getHeight(){
    return mHeight;
}
