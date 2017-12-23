#include "include/init.h"
#include "include/handle.h"
#include "include/print.h"
#include "include/menu.h"
#include <unistd.h>

__color         white = { 255, 255, 255, 255 };
__color         black = { 0, 0, 0, 255 };
__color         red = { 255, 0, 0, 255 };
__color         green = { 0, 255, 0, 255 };
__color         blue = { 0, 0, 255, 255 };

int             width = 1280;
int             height = 720;

SDL_Window     *mainwindow;
SDL_Renderer   *renderer;
SDL_Event      *event;

SDL_Surface    *mainwindowsurface;
SDL_Surface    *startimgsurface;
SDL_Surface *gameimgsurface;

__flags         mainflags;
__flags gameflags;

int
main(int __attribute__ ((unused)) argc, char **
     __attribute__ ((unused)) argv) {
    
    __init();
    __inithandler(&mainflags);
    __initprinter();
    
    mainwindowsurface = NULL;
    mainwindowsurface = SDL_GetWindowSurface(mainwindow);
    __errorcheck(mainwindowsurface,"mainwindow");

    __loadimage(&startimgsurface, "img/main.jpg");
    
    SDL_BlitSurface(startimgsurface, NULL, mainwindowsurface, NULL);

    while (mainflags.running) {

	while (SDL_PollEvent(event)) {
	    __handleevent(event, &mainflags);
	}
	SDL_UpdateWindowSurface(mainwindow);
    }

    __destroyimage(&startimgsurface);
    
    __inithandler(&gameflags);
    __loadimage(&gameimgsurface, "img/game.jpg");
    
    SDL_BlitSurface(gameimgsurface,NULL,mainwindowsurface,NULL);
    
    while (gameflags.running) {

	while (SDL_PollEvent(event)) {
	    __handleevent(event, &gameflags);
	}
	SDL_UpdateWindowSurface(mainwindow);
    }
    __destroyimage(&gameimgsurface);
    __destroyevent(&event);
    __destroysurface(&mainwindowsurface);
    __destroywindow(&mainwindow);
    __destroyrenderer(&renderer);
    __destroyprinter();
    SDL_Quit();
}

int
__init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    mainwindow =
	SDL_CreateWindow("debug", SDL_WINDOWPOS_UNDEFINED,
			 SDL_WINDOWPOS_UNDEFINED, width, height,
			 SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(mainwindow, -1,
				  SDL_RENDERER_ACCELERATED
				  | SDL_RENDERER_PRESENTVSYNC);
    event = (SDL_Event *) malloc(sizeof(SDL_Event));
    __errorcheck(mainwindow, "window");
    __errorcheck(renderer, "renderer");
    __errorcheck(event, "event");
    return 0;
}

int
__loadimage(SDL_Surface ** imagesurface, const char *restrict file) {
    *imagesurface = NULL;
    *imagesurface = IMG_Load(file);
    __errorcheck(*imagesurface, "loadimage");
    return 0;
}

int
__destroyimage(SDL_Surface ** imagesurfaceptr) {
    __errorcheck(*imagesurfaceptr, "destroyimage");
    SDL_FreeSurface(*imagesurfaceptr);
    *imagesurfaceptr = NULL;
    return 0;
}

int
__destroysurface(SDL_Surface ** surfaceptr) {
    __errorcheck(*surfaceptr, "destroysurface");
    SDL_FreeSurface(*surfaceptr);
    *surfaceptr = NULL;
    return 0;
}

int
__destroyevent(SDL_Event ** event) {
    __errorcheck(*event, "destroyevent");
    free(*event);
    return 0;
}

int
__destroyrenderer(SDL_Renderer ** rendererptr) {
    __errorcheck(*rendererptr, "destroyrenderer");
    SDL_DestroyRenderer(*rendererptr);
    *rendererptr = NULL;
    return 0;
}

int
__destroywindow(SDL_Window ** windowptr) {
    __errorcheck(*windowptr, "destroywindow");
    SDL_DestroyWindow(*windowptr);
    return 0;
}

void
__errorcheck(void *object, const char *restrict text) {
    if (object == NULL) {
	perror(text);
	exit(1);
    }
}
