#ifndef __HANDLE_H
#define __HANDLE_H

#include <SDL2/SDL.h>
#include <time.h>

typedef struct {
    int             running;
} __flags;

int             __inithandler(__flags *);
int             __handleevent(SDL_Event *, __flags *);
int             __handlequit(SDL_Event *, __flags *);
int             __handlekey(SDL_Event *, __flags *, SDL_KeyboardEvent *);
int             __handlekeysym(SDL_Event *, __flags *, SDL_Keysym *);
#endif
