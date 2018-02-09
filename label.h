#ifndef __LABEL_H__
#define __LABEL_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "game.h"
#include "widget.h"


struct _Label {
    Widget base;
    const char* text;
    SDL_Color foreground;
    SDL_Color background;
    //TTF_Font *font;
};
typedef struct _Label Label;

int InitLabel(Label *self, Game *mainGm);

void SetText(Label *self, const char *text);

int DrawLabel(Widget *base, SDL_Renderer *rend);

#endif
