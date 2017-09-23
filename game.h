#ifndef __GAME_H__
#define __GAME_H__

//#include "sprite.h"
#include <SDL2/SDL.h>
#define FALSE 0
#define TRUE 1

struct _Game {
  int m_bRunning;
  SDL_Window *gWin;
  SDL_Renderer *gRen;
  SDL_Texture *sprite;
};
typedef struct _Game Game;


Game* InitGame();

//SpriteSheet* InitSprite(const char* file, const char* id);

//void NextSprite(SpriteSheet *self);

//void LoadSprite(Game *self, SpriteSheet *sp);

void DestroyGame(Game* self);

int SDLInit(Game* self, const char* title, int xpos, int ypos, int width, int height, int flags);

void render(Game* self);

void update(Game* self);

void handleEvents(Game* self);

void clean(Game* self);

int running(Game* self);

int mainloop(Game* self);

void callevents(Uint32 event_type, SDL_Event *e);

#endif
