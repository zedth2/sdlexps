#ifndef __TEXTURE_H__
#define __TEXTURE_H__

int load(const char* file, const char* id, SDL_Renderer *ren);

void draw(const char* id, int x, int y, int width, int height, SDL_Renderer *ren, SDL_RendererFlip flip);

#endif
