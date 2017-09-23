//clang -g game.c -o hello `pkg-config --libs sdl2 --libs SDL_image`
// clang++ -g game.c character.c events.c sprite.c  -o hello -lSDL2 -lSDL_image -lSDL -lpthread

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <vector>
#include <string>

#include "widget.h"

#include "game.h"

#include "sprite.h"


Game* gm = 0;
SpriteSheet *sp = 0;
std::map<std::string, SpriteSheet*> m_textMap;
std::vector<Widget*> children;
/*
int mainer(int argc, char* args[]){
  gm = InitGame();
  m_textMap["cecil"] = InitSprite("cecil.bmp");
  m_textMap["cec"] = InitSprite("cecil.bmp");
  m_textMap["cec"]->base->dstRect.x = 100;
  m_textMap["cec"]->base->dstRect.y = 100;
  SDLInit(gm, "TITLE", 100, 100, 640, 480, 0);
  LoadSprite(m_textMap["cecil"], gm);
  LoadSprite(m_textMap["cec"], gm);
  while(gm->m_bRunning){
    handleEvents(gm);
    update(gm);
    SDL_RenderClear(gm->gRen);
    //NextSprite(m_textMap["cecil"]);
    SDL_RenderCopyEx(gm->gRen, m_textMap["cec"]->base->spText, &m_textMap["cec"]->base->srcRect, &m_textMap["cec"]->base->dstRect, 0,0, SDL_FLIP_NONE);
    NextSprite(m_textMap["cec"]);
    SDL_RenderCopyEx(gm->gRen, m_textMap["cecil"]->base->spText, &m_textMap["cecil"]->base->srcRect, &m_textMap["cecil"]->base->dstRect, 0,0, SDL_FLIP_NONE);
    Uint32 z = SDL_GetTicks();
    if(0 == (int)(z % 1000)){
        m_textMap["cec"]->base->dstRect.x++;
        m_textMap["cec"]->base->dstRect.y++;
        if(m_textMap["cec"]->base->dstRect.x > 480) m_textMap["cec"]->base->dstRect.x = 0;
        if(m_textMap["cec"]->base->dstRect.y > 640) m_textMap["cec"]->base->dstRect.y = 0;
    }
    //m_textMap["cec"]->dstRect.x = m_textMap["cec"]->dstRect.x + (int)(((SDL_GetTicks() % 1000)));
    //m_textMap["cec"]->dstRect.y = m_textMap["cec"]->dstRect.y + (int)(((SDL_GetTicks() % 1000)));

    //render(gm, m_textMap["cecil"]);
    //render(gm, m_textMap["cec"]);
    SDL_RenderPresent(gm->gRen);
  }

  clean(gm);
  return 0;
}
*/
void addchild(Game* self, Widget* child){
    return children.push_back(child);
}

int main(int argc, char* args[]){
    gm = InitGame();
    Widget *w = (Widget*) InitSprite("cecil.bmp");
    addchild(gm, w);
    addEventHandler(w, SDL_KEYDOWN, (handle_event)KeyDown);
    mainloop(gm);

    return 0;
}

int mainloop(Game* self){
    while(gm->m_bRunning){
        handleEvents(gm);
        SDL_RenderClear(gm->gRen);
        for(int c = 0; c < children.size(); ++c){
            draw(children[c], gm->gRen);
        }
    }
    return 0;
}

Game* InitGame(){
  Game* self = (Game*) malloc(sizeof(Game));
  self->m_bRunning = 0;
  return self;
}

void DestroyGame(Game* self){}

int SDLInit(Game* self, const char* title, int xpos, int ypos, int width, int height, int flags){
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    printf("SDL Init Success\n");
    self->gWin = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(self->gWin != 0){
      printf("Window creation success\n");
      self->gRen = SDL_CreateRenderer(self->gWin, -1, 0);
      if(self->gRen != 0){
        printf("Renderer creation success\n");
        SDL_SetRenderDrawColor(self->gRen, 255,255,255,255);
      } else {
        printf("Renderer init fail\n");
        return FALSE;
      }
    } else {
      printf("Window init fail\n");
      return FALSE;
    }
  } else {
    printf("SDL init fail\n");
    return FALSE;
  }
  self->m_bRunning = TRUE;
  return TRUE;
}

void render(Game* self){
  //SDL_RenderClear(self->gRen);
  //SDL_RenderCopyEx(self->gRen, sp->spText, &sp->srcRect, &sp->dstRect, 0,0, SDL_FLIP_NONE);
  SDL_RenderPresent(self->gRen);
}

void update(Game* self){}

void handleEvents(Game* self){
    SDL_Event e;
    SDL_PollEvent(&e);
    callevents(e.type, &e);
    /*std::vector<std::string> events;
    if(){
        switch(e.type){
            case SDL_QUIT:
                self->m_bRunning = FALSE;
                break;
            case SDL_KEYDOWN:
                events.push_back("KEY_DOWN");
                break;
            case SDL_KEYUP:
                events.push_back("KEY_DOWN");
                break;
            default: break;
        }
    }
    if(events.size()){
        for(int i = 0; i < events.size(); i++){

        }
    }*/
}

void callevents(Uint32 event_type, SDL_Event *e){
    for(int i = 0; i < children.size(); i++){
        if(children[i]->events.count(event_type)){
            std::vector<handle_event> *child = &children[i]->events[event_type];
            for(int h = 0 ; h < child->size(); ++h){
                (*child)[h](children[i], e, 0);
            }
        }
    }
}
/*
void handleEvents(Game* self){
  SDL_Event e;
  if(SDL_PollEvent(&e)){
    KeyDown(m_textMap["cecil"], SDL_GetKeyboardState( NULL ));
    switch(e.type){
      case SDL_QUIT:
        self->m_bRunning = FALSE;
        break;
      case SDL_KEYDOWN:
        break;
      case SDL_KEYUP:
        break;
      default:
        break;
    }
  }
}
*/
void clean(Game* self){
  printf("Cleaning Game\n");
  SDL_DestroyWindow(self->gWin);
  SDL_DestroyRenderer(self->gRen);
  free(self);
  SDL_Quit();
}
