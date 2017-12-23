#include "include/init.h"
#include "include/handle.h"
#include "include/print.h"

int
main(int __attribute__ ((unused)) argc, char **
     __attribute__ ((unused)) argv) {
    __init();
    __start();
    while (flags.running) {

	while (SDL_PollEvent(event)) {
	    __handleevent(event);
	}
	__update();
    }
    __destroy();
}

int
__init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    width = 1280;
    height = 720;
    window =
	SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED,
			 SDL_WINDOWPOS_UNDEFINED, width, height,
			 SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1,
				  SDL_RENDERER_ACCELERATED
				  | SDL_RENDERER_PRESENTVSYNC);
    event = (SDL_Event *) malloc(sizeof(SDL_Event));
    __errorcheck(window, "window");
    __errorcheck(renderer, "renderer");
    __errorcheck(event, "event");

    __initprinter();
    __inithandler();
    
    return 0;
}

int
__destroy() {
    free(event);
    SDL_FreeSurface(startimgsurface);
    SDL_FreeSurface(windowsurface);
    startimgsurface = NULL;
    windowsurface = NULL;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    __destroyprinter();
    return 0;
}

int
__start() {
    windowsurface = NULL;
    startimgsurface = NULL;
    windowsurface = SDL_GetWindowSurface(window);
    startimgsurface = IMG_Load("./img/main.jpg");
    __errorcheck(windowsurface, "windowsurface");
    __errorcheck(startimgsurface, "startimgsurface");
    SDL_BlitSurface(startimgsurface, NULL, windowsurface, NULL);
    return 0;
}

int
__update() {
    SDL_UpdateWindowSurface(window);
    return 0;
}

void
__errorcheck(void *object, char *objname) {
    if (object == NULL) {
	perror(objname);
	exit(1);
    }
}
