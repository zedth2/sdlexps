#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "game.h"
#include "widget.h"

struct _SpriteSheet {
  Widget *base;
  const char* file;
  unsigned int x;
  unsigned int y;
};
typedef struct _SpriteSheet SpriteSheet;

SpriteSheet* InitSprite(const char* file, Game *mainGm);

void NextSprite(SpriteSheet *self);

void LoadSprite(SpriteSheet *self, Game *mainGm);

int DrawSprite(Widget *self, SDL_Renderer *rend);

void KeyDown(Widget *self, SDL_Event *e, void *extra);

#endif
