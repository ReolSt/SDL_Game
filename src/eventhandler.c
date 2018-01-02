#include "include/library.h"

void
__inithandler(__flags * __attribute__ ((unused)) flags) {
    flags->running = 1;
}

void
__handlequit(SDL_Event * __attribute__ ((unused)) event, __flags *
	     __attribute__ ((unused)) flags) {
    flags->running = 0;
}


void
__handlekey(SDL_Event * __attribute__ ((unused)) event,
	    __flags * __attribute__ ((unused)) flags,
	    SDL_KeyboardEvent * key) {
    switch (key->type) {
    case SDL_KEYUP:
	__printlog("KEYUP\n");
	break;
    case SDL_KEYDOWN:
	__printlog("KEYDOWN\n");
	__handlekeysym(event, flags, &(key->keysym));
	break;
    default:
	break;
    }
}

void
__handlekeysym(SDL_Event * __attribute__ ((unused)) event,
	       __flags * __attribute__ ((unused)) flags,
	       SDL_Keysym * keysym) {
    __printkeysym(event, keysym);
    switch (keysym->sym) {
    case SDLK_ESCAPE:
	__handlequit(event, flags);
	break;
    default:
	break;
    }
}
