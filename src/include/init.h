#ifndef __INIT_H
#define __INIT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#if defined(__LINUX__) || defined(__UNIX__)
#include <unistd.h>
#include <fcntl.h>
#endif

#include <stdio.h>
#include <stdarg.h>

void            __initwindow(SDL_Window **, const char *restrict);
void            __initrenderer(SDL_Renderer **);
void            __getwindowsurface(SDL_Window *, SDL_Surface **);
void            __loadimage(SDL_Surface **, const char *restrict);
void            __loadttf(TTF_Font **, const char *restrict, int);
void            __destroyimage(SDL_Surface **);
void            __destroysurface(SDL_Surface **);
void            __destroyrenderer(SDL_Renderer **);
void            __destroywindow(SDL_Window **);
void            __destroyttf(TTF_Font **);
void            __errorcheck(void *, const char *restrict);
#endif
