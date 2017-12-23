#ifndef __PRINT_H
#define __PRINT_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

FILE           *logfile;

time_t          timer;
struct tm      *t;


int             __initprinter();
int             __destroyprinter();
int             __printlog(const char *restrict str, ...);
int             __printstart(SDL_Event *);
int             __printend(SDL_Event *);
int             __printtime(SDL_Event *, time_t *, struct tm *);
int             __printquit(SDL_Event * event);
int             __printkeysym(SDL_Event * event, SDL_Keysym * keysym);
#endif
