#include "game.h"


game::game(){
    window=NULL;
    Running=true;
}


/**
*central loop calling all other functions
*@return 0 if successful, -1 on fail
*/
int game::OnExecute(){
    if(OnInit()==false){
        return -1;
    }
    while(Running){
        while(SDL_PollEvent(&Event)){
            OnEvent(&Event);
        }
        if(!OnLoop())
            Running=false;
        if(!OnRender())
            Running=false;
    }
    Cleanup();
    return 0;
}




/**
*initial main function
*@return 0 if successful, -1 on fail
*/
int main(int argc, char* argv[]){
    game SuperGame;
    return SuperGame.OnExecute();
}
