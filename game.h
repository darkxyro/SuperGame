#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "includes.h"


class game{

private:

    const int SCREEN_WIDTH=1280;
    const int SCREEN_HEIGHT=960;
    const unsigned long MAX_FPS=60;
    const std::string STD_FONT="OptimusPrinceps.ttf";

    FPSCounter mFpsCounter;

    bool Running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event Event;

    std::unordered_map<std::string,WTexture*> mTextures;

    SDL_Rect clips[4];
    int useClip;
    bool mPaused;

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
