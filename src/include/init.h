#ifndef __INIT_H
#define __INIT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdarg.h>

int             width;
int             height;

int             __init();
int             __destroy();
int             __loadimage(SDL_Surface **, const char *restrict);
int             __destroyimage(SDL_Surface **);
int             __destroysurface(SDL_Surface **);
int             __destroyevent(SDL_Event **);
int             __destroyrenderer(SDL_Renderer **);
int             __destroywindow(SDL_Window **);
void            __errorcheck(void *, const char *restrict);
#endif
