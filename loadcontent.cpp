#include "game.h"


/**
*loads required content at startup
*@return true if successful, else false
*/
bool game::LoadContent(){
    cout<<"Resource Path: "<<getResourcePath()<<endl;
    string resPath=getResourcePath();
    tex=loadTexture(resPath+"image.bmp", renderer);
    backg=loadTexture(resPath+"background.bmp", renderer);
    if(tex==NULL||backg==NULL)
        return false;
    return true;
}


/**
* loads a BMP image into a texture on the rendering device
* @param file The BMP image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* game::loadTexture(const string &file, SDL_Renderer* ren){
    SDL_Texture* tex=NULL;
    SDL_Surface* bmp=SDL_LoadBMP(file.c_str());
    if(bmp!=NULL){
        tex=SDL_CreateTextureFromSurface(ren, bmp);
        SDL_FreeSurface(bmp);
        if(tex==NULL)
            logSDLError(cout,"CreateTextureFromSurface");
    }
    else
        logSDLError(cout,"LoadBMP");
    return tex;
}
