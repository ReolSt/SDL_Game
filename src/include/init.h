#ifndef __INIT_H
#define __INIT_H
#include "library.h"

void            __initwindow(SDL_Window **, const char *restrict);
void            __initrenderer(SDL_Renderer **);
void            __getwindowsurface(SDL_Window *, SDL_Surface **);
void            __loadimage(SDL_Texture **, SDL_Renderer *,
			    const char *restrict);
void            __loadttf(TTF_Font **, const char *restrict, int);
#endif
