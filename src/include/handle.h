#ifndef __HANDLE_H
#define __HANDLE_H

#include <SDL2/SDL.h>
#include <time.h>

typedef struct __flags {
    int             running;
    int             update;
} Flags;

Flags           flags;

int             __handleevent(SDL_Event *);
int             __handlequit(SDL_Event * __attribute((unused)));
int             __handlekey(SDL_Event * __attribute__ ((unused)),
			    SDL_KeyboardEvent *);
int             __handlekeysym(SDL_Event * __attribute__ ((unused)),
			       SDL_Keysym *);
#endif
