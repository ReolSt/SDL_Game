#ifndef __DRAW_H
#include <SDL2/SDL.h>
#include <stdio.h>
int             x;
int             y;

/*
 * int __setrendererdrawcolor(SDL_Renderer *); 
 */
int             __setrdc(SDL_Renderer *, int color);
int             __drawline(int destx, int desty);
int             __drawrect(int size);
#endif
