
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "game.h"
#include "widget.h"
#include "label.h"



TTF_Font* FontInit(const char* fontpath, int ptsize){
    TTF_Font *font = TTF_OpenFont(fontpath, ptsize);
    if(NULL == font){
        printf("ERROR : Failed to load font. %s\n", TTF_GetError());
        return NULL;
    }

    return font;
}


int InitLabel(Label *self, Game *mainGm){
    printf("INITING LABEL\n");
    initWidget(&(self->base));
    printf("INITING WIDGETS\n");
    self->base.draw = &DrawLabel;
    //self->font = FontInit("/usr/share/fonts/TTF/DejaVuSerifCondensed.ttf", 18);
    //if(NULL == self->font){

        //return 0;
    //}

    return 1;
}

void SetText(Label *self, const char *text){
    self->text = text;
}


int DrawLabel(Widget *base, SDL_Renderer *rend){
    Label *self = (Label*)base;
    SDL_Surface* surface = SDL_CreateRGBSurface(0, base->srcRect.w, base->srcRect.h, DEFAULT_COLOR_DEPTH, 0, 0, 0, 0);
    SDL_FillRect(surface, &base->srcRect, SDL_MapRGB(surface->format, self->background.r, self->background.g, self->background.b));

    return 0;
}
