#ifndef __HANDLE_H
#define __HANDLE_H

#include "library.h"

typedef struct {
    int8_t           running;
    int8_t           init;
    int8_t           start;
    int8_t           movex;
    int8_t           movey;
    int8_t           mousemotion;
    int8_t           xrel;
    int8_t           yrel;
} __flags;

int             __inithandler(__flags *);
int             __handleevent(SDL_Event *, __flags *);
int             __handlequit(SDL_Event *, __flags *);
int             __handlekey(SDL_Event *, __flags *, SDL_KeyboardEvent *);
int             __handlekeysym(SDL_Event *, __flags *, SDL_Keysym *);
int             __handlemousebutton(SDL_Event *, __flags *,
				    SDL_MouseButtonEvent *);
int             __handlemousemotion(SDL_Event *, __flags *,
				    SDL_MouseMotionEvent *);
#endif
