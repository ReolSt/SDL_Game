#include "include/library.h"

int
__inithandler(__flags * __attribute__ ((unused)) flags) {
    flags->running = 1;
    return 0;
}

int
__handleevent(SDL_Event * event, __flags * __attribute__ ((unused)) flags) {
    __printlog("\n");
    switch (event->type) {
    case SDL_KEYUP:
    case SDL_KEYDOWN:
	__handlekey(event, flags, &(event->key));
	break;
    case SDL_MOUSEBUTTONUP:
    case SDL_MOUSEBUTTONDOWN:
	__printmousebutton(event, &(event->button));
	__handlemousebutton(event, flags, &(event->button));
	break;
    case SDL_MOUSEMOTION:
	__printmousemotion(event, &(event->motion));
	__handlemousemotion(event, flags, &(event->motion));
	break;
    case SDL_QUIT:
	__printquit(event);
	__handlequit(event, flags);
	break;
    default:
	break;
    }
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
	break;
    case SDL_KEYDOWN:
	__printlog("KEYDOWN\n");
	__handlekeysym(event, flags, &(key->keysym));
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
    case SDLK_UP:
	flags->movey=-1;
	break;
    case SDLK_DOWN:
	flags->movey=1;
	break;
    case SDLK_LEFT:
	flags->movex=-1;
	break;
    case SDLK_RIGHT:
	flags->movex=1;
	break;
    default:
	break;
    }
    return 0;

}

int
__handlemousebutton(SDL_Event * __attribute__ ((unused)) event,
		    __flags * __attribute__ ((unused)) flags,
		    SDL_MouseButtonEvent * mousebutton) {
    switch (mousebutton->button) {
    case SDL_BUTTON_LEFT:
	break;
    case SDL_BUTTON_MIDDLE:
	break;
    case SDL_BUTTON_RIGHT:
	break;
    case SDL_BUTTON_X1:
	break;
    case SDL_BUTTON_X2:
	break;
    default:
	break;
    }

    return 0;
}

int
__handlemousemotion(SDL_Event * __attribute__ ((unused)) event,
		    __flags * __attribute__ ((unused)) flags,
		    SDL_MouseMotionEvent * mousemotion) {
    if(flags->mousemotion==1) {
	flags->mousemotion=0;
    }
    else {
	    flags->xrel = mousemotion->xrel;
            flags->yrel = mousemotion->yrel;
            flags->mousemotion = 1;

    }
    return 0;
}
