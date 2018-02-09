#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>

#include "widget.h"
#include "sprite.h"
#include "game.h"

int InitSprite(SpriteSheet *self, const char* file, Game *mainGm){
  initWidget(&(self->base));
  self->file = file;
  self->x = 82;
  self->y = 8;
  self->base.srcRect.x = 82;
  self->base.srcRect.y = 8;
  self->base.srcRect.w = 16;
  self->base.srcRect.h = 16;
  self->base.dstRect.x = 0;
  self->base.dstRect.y = 0;
  self->base.dstRect.w = 48;
  self->base.dstRect.h = 48;
  self->base.draw = DrawSprite;
  LoadSprite(self, mainGm);
  return 0;
}

void NextSprite(SpriteSheet *self){

  self->base.srcRect.x = self->x + (self->base.srcRect.w * (int)(((SDL_GetTicks() / 500) % 4)));
  //printf("RESULT %d + %d = %d %d\n", self->x, (self->base.srcRect.w * (int)(((SDL_GetTicks() / 500) % 4))), self->base.srcRect.x, self->base.srcRect.w);
  //self->base.srcRect.x += 1 + self->base.srcRect.w;
  //if(self->srcRect.x > 148){self->srcRect.x = self->x;}
  //self->base.srcRect.y += 1 + self->base.srcRect.w;
}

void LoadSprite(SpriteSheet *self, Game *mainGm){
  SDL_Surface *tmp = SDL_LoadBMP(self->file);
  if(tmp == NULL){
    printf( "SDL Error: %s\n", SDL_GetError() );
    return;
  }
  self->base.spText = SDL_CreateTextureFromSurface(mainGm->gRen, tmp);
  SDL_FreeSurface(tmp);
  //SDL_QueryTexture(sp->spText, NULL, NULL, &sp->srcRect.w, &sp->srcRect.h);
}

int DrawSprite(Widget *wid, SDL_Renderer *rend){

    SpriteSheet *self = (SpriteSheet*)wid;
    //printf("X %d \n", self->x);
    NextSprite(self);
    //printf("SPRITE DRAW %d \n", self->base.srcRect.x);
    widget_draw(wid, rend);
    //SDL_RenderCopyEx(rend, self->base.spText, &self->base.srcRect, &self->base.dstRect, 0, 0, SDL_FLIP_NONE);
    return 0;
}

void MoveSprite(SpriteSheet *self, int xMove, int yMove){
    self->base.dstRect.y += yMove;
    self->base.dstRect.x += xMove;
}


void KeyDown(Widget *self, SDL_Event *e, void *extra){
    printf("KEY DOWN SPRITE\n");
    //printf("KEY %d %d \n", e->key.keysym, SDL_GetScancodeFromKey(e->key.keysym));
    if(e->key.keysym.scancode == SDL_SCANCODE_UP){
        self->dstRect.y--;
    }
    if(e->key.keysym.scancode == SDL_SCANCODE_DOWN){
        self->dstRect.y++;
    }
    if(e->key.keysym.scancode == SDL_SCANCODE_LEFT){
        self->dstRect.x--;
    }
    if(e->key.keysym.scancode == SDL_SCANCODE_RIGHT){
        self->dstRect.x++;
    }
/*
    if(eve[SDL_SCANCODE_UP]){
        self->dstRect.y--;
    }
    if( eve[ SDL_SCANCODE_DOWN ] )
    {
        self->dstRect.y++;
    }
    if( eve[ SDL_SCANCODE_LEFT ] )
    {
        self->dstRect.x--;
    }
    if( eve[ SDL_SCANCODE_RIGHT ] )
    {
        self->dstRect.x++;
    }
    //else
    //{
        //printf("Well
    //}*/
}
