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
    if (window == NULL) {
	perror("window");
	exit(1);
    }
    if (renderer == NULL) {
	perror("renderer");
	exit(1);
    }
    if (event == NULL) {
	perror("event");
	exit(1);
    }
    __initprinter();
    flags.running = 1;
    flags.update = 1;
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
    startimgsurface = SDL_LoadBMP("./img/main.bmp");
    SDL_BlitSurface(startimgsurface, NULL, windowsurface, NULL);
    if (windowsurface == NULL) {
	perror("windowsurface");
	exit(1);
    }
    if (startimgsurface == NULL) {
	perror("startimgsurface");
	exit(1);
    }
    return 0;
}

int
__update() {
    SDL_UpdateWindowSurface(window);
    return 0;
}
