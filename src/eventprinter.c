#include "include/print.h"

FILE           *logfile;

time_t          timer;
struct tm      *t;

int
__initprinter() {
    logfile = fopen("log/event", "w");
    return 0;
}

int
__destroyprinter() {
    fclose(logfile);
    return 0;
}
int
__printlog(const char *restrict str, ...) {
    va_list         params;
    va_start(params, str);
    vfprintf(stdout, str, params);
    va_end(params);
    va_start(params, str);
    vfprintf(logfile, str, params);
    va_end(params);
    return 0;
}

int
__printstart(SDL_Event * __attribute__ ((unused)) event) {
    __printlog("---EVENT---\n");
    __printtime(event, &timer, t);
    return 0;
}

int
__printend(SDL_Event * __attribute__ ((unused)) event) {
    __printlog("--EVENT---\n");
    return 0;
}

int
__printtime(SDL_Event * __attribute__ ((unused)) event, time_t * timer,
	    struct tm *t) {
    *timer = time(NULL);
    t = localtime(timer);
    __printlog("%d:%d.%d\n", t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}

int
__printquit(SDL_Event * __attribute__ ((unused)) event) {
    __printlog("QUIT\n");
    return 0;
}

int
__printrunningend(SDL_Event * __attribute ((unused)) event) {
    // not yet
    return 0;
}
int
__printkeysym(SDL_Event * __attribute__ ((unused)) event,
	      SDL_Keysym * keysym) {
    __printlog("keyname : %s keysym : %d\n", SDL_GetKeyName(keysym->sym),
	       keysym->sym);
    return 0;
}
