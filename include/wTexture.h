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
        void free();
        void render(SDL_Renderer* renderer,SDL_Rect* pos,SDL_Rect* Clip=NULL);
        void render(SDL_Renderer* renderer,int x,int y,SDL_Rect* Clip=NULL);
        int getWidth();
        int getHeight();
};


#endif//WTEXTURE_H_INCLUDED
