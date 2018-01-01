#ifndef __PRINT_H
#define __PRINT_H

#include "library.h"

void            __initprinter();
void            __destroyprinter();
void            __printlog(const char *restrict, ...);
void            __printstart(SDL_Event *);
void            __printend(SDL_Event *);
void            __printtime(SDL_Event *, time_t *, struct tm *);
void            __printquit(SDL_Event *);
void            __printrunningend(SDL_Event *);
void            __printkeysym(SDL_Event *, SDL_Keysym *);
void            __printmousebutton(SDL_Event *, SDL_MouseButtonEvent *);
void            __printmousemotion(SDL_Event *, SDL_MouseMotionEvent *);

#endif
