#ifndef __DESTROY_H
#define __DESTROY_H

#include "library.h"

void            __destroyimage(SDL_Surface **);
void            __destroysurface(SDL_Surface **);
void            __destroytexture(SDL_Texture **);
void            __destroyrenderer(SDL_Renderer **);
void            __destroywindow(SDL_Window **);
void            __destroyttf(TTF_Font **);

#endif
