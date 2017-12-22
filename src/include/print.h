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
int             __printstart(SDL_Event * __attribute__ ((unused)));
int             __printend(SDL_Event * __attribute__ ((unused)));
int             __printtime(SDL_Event * __attribute__ ((unused)), time_t *,
			    struct tm *);
int             __printquit(SDL_Event * __attribute__ ((unused)) event);
int             __printkeysym(SDL_Event * __attribute__ ((unused)) event,
			      SDL_Keysym * keysym);
#endif
