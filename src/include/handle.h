#ifndef __HANDLE_H
#define __HANDLE_H

#include "library.h"

typedef struct {
    int8_t          running;
    int8_t          init;
} __flags;

int             __inithandler(__flags *);
int             __handleevent(SDL_Event *, __flags *);
int             __handlequit(SDL_Event *, __flags *);
int             __handlekey(SDL_Event *, __flags *, SDL_KeyboardEvent *);
SDL_Keysym     *__handlekeysym(SDL_Event *, __flags *, SDL_Keysym *);
SDL_MouseButtonEvent *__handlemousebutton(SDL_Event *, __flags *,
					  SDL_MouseButtonEvent *);
SDL_MouseMotionEvent *__handlemousemotion(SDL_Event *, __flags *,
					  SDL_MouseMotionEvent *);
#endif
