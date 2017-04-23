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
    return true;
}
