#include "widget.h"
#include <vector>
#include <SDL2/SDL.h>
#include <map>
Widget* initWidget(){
    Widget *w = (Widget*)malloc(sizeof(Widget));
    w->events = std::map<Uint32, std::vector<handle_event> >();
    return w;
}

int addEventHandler(Widget *wid, Uint32 key, handle_event callback){
    if(!wid->events.count(key)){
        std::vector<handle_event> handles;
        //std::map<int, std::vector<handle_event> > events;
        wid->events[key] = std::vector<handle_event>(); ////It segfaults here and I'm really not sure why.
        //wid->events.insert(std::pair<Uint32, handle_event>(10, ()));
    }
    wid->events[key].push_back(callback);
    return 1;

}

int draw(Widget *self, SDL_Renderer *rend){
    return SDL_RenderCopyEx(rend, self->spText, &self->srcRect, &self->dstRect, 0, 0, SDL_FLIP_NONE);
}
