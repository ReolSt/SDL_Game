#ifndef __PRINT_H
#define __PRINT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int             __initprinter();
int             __destroyprinter();
int             __printlog(const char *restrict, ...);
int             __printstart(SDL_Event *);
int             __printend(SDL_Event *);
int             __printtime(SDL_Event *, time_t *, struct tm *);
int             __printquit(SDL_Event *);
int             __printrunningend(SDL_Event *);
int             __printkeysym(SDL_Event *, SDL_Keysym *);
#endif
