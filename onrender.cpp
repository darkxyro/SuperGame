#include "game.h"

using namespace std;
/**
*standard render function called on every iteration
*@return true if successful, else false
*/
bool game::OnRender(){
    SDL_RenderClear(renderer);
    int xTiles=SCREEN_WIDTH/mTextures["grass"]->getWidth()+1;
    int yTiles=SCREEN_HEIGHT/mTextures["grass"]->getHeight()+1;
    for(int i=0;i<xTiles*yTiles;i++){
        int x=(i%xTiles)*mTextures["grass"]->getWidth();
        int y=(i/xTiles)*mTextures["grass"]->getHeight();
        mTextures["grass"]->render(renderer,x,y);
    }
    string fontPath=getResourcePath()+"OptimusPrinceps.ttf";
    int fps=mFpsCounter.getFPS();
    string message="FPS: "+to_string(fps);
    SDL_Color col={255,255,255,255};
    SDL_Texture *text = renderText(message, fontPath, col, 16);
    int pW,pH;
    if(text!=NULL){
        SDL_QueryTexture(text,NULL,NULL,&pW,&pH);
        int x=(SCREEN_WIDTH-pW)*3/4;
        int y=16;
        renderTexture(text,x,y);
    }
    SDL_RenderPresent(renderer);
    return true;
}



/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
* width and height
* @param tex The source texture we want to draw
* @param dst The destination rectangle to render the texture to
* @param clip The sub-section of the texture to draw (clipping rect) default of nullptr draws the entire texture
*/
void game::renderTexture(SDL_Texture* tex,SDL_Rect dst, SDL_Rect* clip){
    SDL_RenderCopy(renderer,tex,clip,&dst);
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height
* @param tex The source texture we want to draw
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param clip The sub-section of the texture to draw (clipping rect) default of nullptr draws the entire texture
*/
void game::renderTexture(SDL_Texture* tex,int x,int y, SDL_Rect* clip){
	SDL_Rect dst;
	dst.x=x;
	dst.y=y;
	if(clip!=NULL){
        dst.w=clip->w;
        dst.h=clip->h;
	}
	else
        SDL_QueryTexture(tex,NULL,NULL,&dst.w,&dst.h);
	renderTexture(tex,dst,clip);
}


/**
* Render the message we want to display to a texture for drawing
* @param message The message we want to display
* @param fontFile The font we want to use to render the text
* @param color The color we want the text to be
* @param fontSize The size we want the font to be
* @return An SDL_Texture containing the rendered message, or nullptr if something went wrong
*/
SDL_Texture* game::renderText(const string &message, const string &fontFile,SDL_Color color, int fontSize)
{
	//Open the font
	TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == nullptr){
		logSDLError(cout, "TTF_OpenFont");
		return nullptr;
	}
	//We need to first render to a surface as that's what TTF_RenderText
	//returns, then load that surface into a texture
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	if (surf == nullptr){
		TTF_CloseFont(font);
		logSDLError(cout, "TTF_RenderText");
		return nullptr;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == nullptr){
		logSDLError(cout, "CreateTexture");
	}
	//Clean up the surface and font
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}



