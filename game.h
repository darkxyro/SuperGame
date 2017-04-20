#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "includes.h"



class game{

private:

    const int SCREEN_WIDTH=1280;
    const int SCREEN_HEIGHT=960;


    bool Running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event Event;
    SDL_Texture* tex;
    SDL_Texture* backg;



    SDL_Texture* loadTexture(const string &file, SDL_Renderer* ren);
    void renderTexture(SDL_Texture*,SDL_Renderer*,int,int);

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
