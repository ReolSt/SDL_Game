#include "include/handle.h"
#include "include/print.h"

int
__inithandler(__flags * __attribute__ ((unused)) flags) {
    flags->running = 1;
    return 0;
}

int
__handleevent(SDL_Event * event, __flags * __attribute__ ((unused)) flags) {
    __printstart(event);
    switch (event->type) {
    case SDL_KEYUP:
    case SDL_KEYDOWN:
	__handlekey(event, flags, &(event->key));
	break;
    case SDL_QUIT:
	__printquit(event);
	__handlequit(event, flags);
	break;
    default:
	__printend(event);
    }
    __printend(event);
    return 0;
}

int
__handlequit(SDL_Event * __attribute__ ((unused)) event, __flags *
	     __attribute__ ((unused)) flags) {
    flags->running = 0;
    __printquit(event);
    return 0;
}


int
__handlekey(SDL_Event * __attribute__ ((unused)) event,
	    __flags * __attribute__ ((unused)) flags,
	    SDL_KeyboardEvent * key) {
    switch (key->type) {
    case SDL_KEYUP:
	__printlog("KEYUP\n");
	__handlekeysym(event, flags, &(key->keysym));
	break;
    case SDL_KEYDOWN:
	__printlog("KEYDOWN\n");
	break;
    default:
	break;
    }
    return 0;
}

int
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
    return 0;

}
