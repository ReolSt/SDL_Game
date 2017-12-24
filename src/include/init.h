#ifndef __INIT_H
#define __INIT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#if defined(__LINUX__) || defined(__UNIX__)
#include <unistd.h>
#include <fctnl.h>
#endif

#include <stdio.h>
#include <stdarg.h>

int             width;
int             height;

void            __initwindow(SDL_Window **, const char *restrict);
void            __initrenderer(SDL_Renderer **);
void            __getwindowsurface(SDL_Window *, SDL_Surface **);
void            __loadimage(SDL_Surface **, const char *restrict);
void            __destroyimage(SDL_Surface **);
void            __destroysurface(SDL_Surface **);
void            __destroyrenderer(SDL_Renderer **);
void            __destroywindow(SDL_Window **);
void            __errorcheck(void *, const char *restrict);
#endif
