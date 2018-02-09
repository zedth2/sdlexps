#ifndef __WIDGET_H__
#define __WIDGET_H__
#include <SDL2/SDL.h>
#include <map>
#include <vector>
#include <string>

#define DEFAULT_COLOR_DEPTH 32

typedef struct _widget Widget;

typedef int (*handle_event)(Widget *self, SDL_Event *event, void *extra);

struct _widget {
    SDL_Texture *spText;
    SDL_Rect srcRect;
    SDL_Rect dstRect;
    std::map<Uint32, std::vector<handle_event> > events;
    int (*draw)(Widget*, SDL_Renderer*);
};


int initWidget(Widget *self);

int addEventHandler(Widget *wid, Uint32 key, handle_event callback);

int widget_draw(Widget *self, SDL_Renderer *rend);

#endif
