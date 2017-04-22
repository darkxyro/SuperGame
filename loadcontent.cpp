#include "game.h"

using namespace std;

/**
*loads required content at startup
*@return true if successful, else false
*/
bool game::LoadContent(){
    cout<<"Resource Path: "<<getResourcePath()<<endl;
    string resPath=getResourcePath();
    mTextures.emplace("grass",new WTexture);
    if(!mTextures["grass"]->loadTexture(renderer,resPath+"grass.png")){
        mTextures["grass"]->free();
        return false;
    }
    /*mTextures.push_back(tex);
    if(!mTextures[1].loadTexture(renderer,resPath+"image.png")){
        mTextures[1].free();
        return false;
    }*/
    return true;
}



/**
* loads a BMP image into a texture on the rendering device
* @param file The BMP image file to load
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* game::loadTexture(const string &file){
    SDL_Texture* tex=IMG_LoadTexture(renderer,file.c_str());
    if(tex==NULL)
        logSDLError(cout,"IMG_LoadTexture");
    return tex;
}
