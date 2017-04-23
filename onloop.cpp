#include "game.h"

using namespace std;
/**
*standard loop called on every iteration
*@return true if successful, else false
*/
bool game::OnLoop(){
    if(!mPaused){
        mFpsCounter.updateClock();
    }
    return true;
}
