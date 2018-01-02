#ifndef __HANDLE_H
#define __HANDLE_H

#include "library.h"

typedef struct {
    int8_t          running;
    int8_t          init;
} __flags;

void            __inithandler(__flags *);
void            __handleevent(SDL_Event *, __flags *);
void            __handlequit(SDL_Event *, __flags *);
void            __handlekey(SDL_Event *, __flags *, SDL_KeyboardEvent *);
void            __handlekeysym(SDL_Event *, __flags *, SDL_Keysym *);
void            __handlemousebutton(SDL_Event *, __flags *,
				    SDL_MouseButtonEvent *);
void            __handlemousemotion(SDL_Event *, __flags *,
				    SDL_MouseMotionEvent *);
#endif
