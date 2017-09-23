#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "widget.h"
#include "sprite.h"
#include "game.h"

SpriteSheet* InitSprite(const char* file){
  SpriteSheet *self = (SpriteSheet*)malloc(sizeof(SpriteSheet));
  self->base = initWidget();
  self->file = file;
  self->x = 82;
  self->y = 8;
  self->base->srcRect.x = 82;
  self->base->srcRect.y = 8;
  self->base->srcRect.w = 16;
  self->base->srcRect.h = 16;
  self->base->dstRect.x = 0;
  self->base->dstRect.y = 0;
  self->base->dstRect.w = 48;
  self->base->dstRect.h = 48;
  //m_textMap[id] = self;
  return self;
}

void NextSprite(SpriteSheet *self){
  self->base->srcRect.x = self->x + (self->base->srcRect.w * (int)(((SDL_GetTicks() / 500) % 4)));
  //self->srcRect.x += 1 + self->srcRect.w;
  //if(self->srcRect.x > 148){self->srcRect.x = self->x;}
  //self->srcRect.y += 1 + self->srcRect.w;
}

void LoadSprite(SpriteSheet *self, Game *mainGm){
  SDL_Surface *tmp = SDL_LoadBMP(self->file);
  if(tmp == NULL){
    printf( "SDL Error: %s\n", SDL_GetError() );
    return;
  }
  self->base->spText = SDL_CreateTextureFromSurface(mainGm->gRen, tmp);
  SDL_FreeSurface(tmp);
  //SDL_QueryTexture(sp->spText, NULL, NULL, &sp->srcRect.w, &sp->srcRect.h);
}

void DrawSprite(SpriteSheet *self, Game *mainGm){
    SDL_RenderCopyEx(mainGm->gRen, self->base->spText, &self->base->srcRect, &self->base->dstRect, 0, 0, SDL_FLIP_NONE);
}

void MoveSprite(SpriteSheet *self, int xMove, int yMove){
    self->base->dstRect.y += yMove;
    self->base->dstRect.x += xMove;
}


void KeyDown(Widget *self, SDL_Event *e, void *extra){
    printf("KEY DOWN");
    /*
    if(eve[SDL_SCANCODE_UP]){
        self->base->dstRect.y--;
    }
    if( eve[ SDL_SCANCODE_DOWN ] )
    {
        self->base->dstRect.y++;
    }
    if( eve[ SDL_SCANCODE_LEFT ] )
    {
        self->base->dstRect.x--;
    }
    if( eve[ SDL_SCANCODE_RIGHT ] )
    {
        self->base->dstRect.x++;
    }*/
    //else
    //{
        //printf("Well
    //}
}
