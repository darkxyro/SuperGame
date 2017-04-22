#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "includes.h"


class game{

private:

    const int SCREEN_WIDTH=1280;
    const int SCREEN_HEIGHT=960;
    const unsigned long MAX_FPS=60;

    FPSCounter mFpsCounter;

    bool Running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event Event;

    std::unordered_map<std::string,WTexture*> mTextures;

    SDL_Rect clips[4];
    int useClip;



    SDL_Texture* loadTexture(const std::string &file);
    SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize);
    void renderTexture(SDL_Texture* tex,SDL_Rect dst, SDL_Rect* clip=NULL);
    void renderTexture(SDL_Texture* tex,int x,int y, SDL_Rect* clip=NULL);
    void loadFont(int);

public:
    game();
    int OnExecute();
    bool OnInit();
    bool LoadContent();
    void OnEvent(SDL_Event* Event);
    bool OnLoop();
    bool OnRender();
    void Cleanup();
};



#endif // GAME_H_INCLUDED
