#include "include/library.h"

FILE           *logfile;

time_t          timer;
struct tm      *t;

void
__initprinter() {
    logfile = fopen("log/event", "w");
    __errorcheck(logfile, "initprinter");
}

void
__destroyprinter() {
    __errorcheck(logfile, "destroyprinter");
    fclose(logfile);
}

void
__printlog(const char *restrict str, ...) {
    va_list         params;
    va_start(params, str);
    vfprintf(stdout, str, params);
    va_end(params);
    va_start(params, str);
    vfprintf(logfile, str, params);
    va_end(params);
}

void
__printtime(SDL_Event * __attribute__ ((unused)) event, time_t * timer,
	    struct tm *t) {
    *timer = time(NULL);
    t = localtime(timer);
    __printlog("%d:%d.%d\n", t->tm_hour, t->tm_min, t->tm_sec);
}

void
__printquit(SDL_Event * __attribute__ ((unused)) event) {
    __printlog("QUIT\n");
}

void
__printkeysym(SDL_Event * __attribute__ ((unused)) event,
	      SDL_Keysym * keysym) {
    __printlog("mod : %d, scancode : %d\n", keysym->mod, keysym->scancode);
    __printlog("keyname : %s keysym : %d\n", SDL_GetKeyName(keysym->sym),
	       keysym->sym);
    __printlog("unused : %d\n", keysym->unused);
}

void
__printmousebutton(SDL_Event * __attribute__ ((unused)) event,
		   SDL_MouseButtonEvent * button) {
    __printlog("timestamp : %d\n", button->timestamp);
    __printlog("x : %d y : %d\n", button->x, button->y);
    __printlog("state : %d, clicks : %d, button : %d\n", button->state,
	       button->clicks, button->button);
    __printlog("padding1 : %d, type : %d, which : %d, windowID : %d\n",
	       button->padding1, button->type, button->which,
	       button->windowID);
}

void
__printmousemotion(SDL_Event * __attribute__ ((unused)) event,
		   SDL_MouseMotionEvent * motion) {
    __printlog("timestamp : %d\n", motion->timestamp);
    __printlog("x : %d y : %d xrel : %d yrel : %d\n", motion->x, motion->y,
	       motion->xrel, motion->yrel);
    __printlog("state : %d\n", motion->state);
    __printlog("type : %d, which : %d, windowID : %d\n", motion->type,
	       motion->which, motion->windowID);
}
