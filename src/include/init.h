#ifndef __INIT_H
#define __INIT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
int             width;
int             height;

SDL_Window     *window;
SDL_Renderer   *renderer;
SDL_Event      *event;

SDL_Surface    *windowsurface;
SDL_Surface    *startimgsurface;


int             __init();
int             __destroy();
int             __start();
int             __update();
int             __initflags();
void            __errorcheck(void *, char *);
#endif
