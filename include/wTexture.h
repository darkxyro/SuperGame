#ifndef WTEXTURE_H_INCLUDED
#define WTEXTURE_H_INCLUDED

#include "../includes.h"

class WTexture{
    private:
        SDL_Texture* mTexture;
        int mWidth;
        int mHeight;
    public:
        WTexture();
        ~WTexture();
        bool loadTexture(SDL_Renderer* renderer,const std::string& file);
        bool loadFromText(SDL_Renderer* renderer,const std::string message,SDL_Color col,int fontSize,const std::string fontFileName);
        bool loadFromText(SDL_Renderer* renderer,const std::string message,SDL_Color col,TTF_Font* font);
        void free();
        void render(SDL_Renderer* renderer,SDL_Rect* pos,SDL_Rect* Clip=NULL,double angle=0.0,SDL_Point* center=NULL,SDL_RendererFlip flip=SDL_FLIP_NONE);
        void render(SDL_Renderer* renderer,int x,int y,SDL_Rect* Clip=NULL,double angle=0.0,SDL_Point* center=NULL,SDL_RendererFlip flip=SDL_FLIP_NONE);
        int getWidth();
        int getHeight();
};


#endif//WTEXTURE_H_INCLUDED
