
#include "texture.h"

int load(const char* file, const char* id, SDL_Renderer *ren){
    SDL_Surface *tmpSf = IMG_Load(file);
    if(tmpSf == 0){
        return false;
    }

    SDL_Texture *txt = SDL_CreateTextureFromSurface(ren, tmpSf);

    SDL_FreeSurface(tmpSf);

    if(txt != 0){

    }
}

void draw(const char* id, int x, int y, int width, int height, SDL_Renderer *ren, SDL_RendererFlip flip){

}
