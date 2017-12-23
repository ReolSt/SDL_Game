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
SDL_Event       event;
SDL_Event       gameevent;
SDL_Surface    *mainwindowsurface;
SDL_Surface    *startimgsurface;
SDL_Surface    *gameimgsurface;

// handler
__flags         mainflags;
__flags         gameflags;

int
main(int __attribute__ ((unused)) argc, char **
     __attribute__ ((unused)) argv) {

    SDL_Init(SDL_INIT_EVERYTHING);
    __initwindow(&mainwindow, "debug");
    __initrenderer(&renderer);
    __inithandler(&mainflags);
    __initprinter();

    __getwindowsurface(mainwindow, &mainwindowsurface);

    __loadimage(&startimgsurface, "img/main.jpg");

    SDL_BlitSurface(startimgsurface, NULL, mainwindowsurface, NULL);

    while (mainflags.running) {

	while (SDL_PollEvent(&event)) {
	    __handleevent(&event, &mainflags);
	}
	SDL_UpdateWindowSurface(mainwindow);
    }

    __destroyimage(&startimgsurface);


    __inithandler(&gameflags);

    __loadimage(&gameimgsurface, "img/game.jpg");

    SDL_BlitSurface(gameimgsurface, NULL, mainwindowsurface, NULL);

    while (gameflags.running) {

	while (SDL_PollEvent(&gameevent)) {
	    __handleevent(&gameevent, &gameflags);
	}
	SDL_UpdateWindowSurface(mainwindow);
    }

    sleep(1);

    __destroyimage(&gameimgsurface);
    __destroysurface(&mainwindowsurface);
    __destroywindow(&mainwindow);
    __destroyrenderer(&renderer);
    __destroyprinter();
    SDL_Quit();
}

void
__initwindow(SDL_Window ** windowptr, const char *restrict text) {
    *windowptr =
	SDL_CreateWindow(text, SDL_WINDOWPOS_UNDEFINED,
			 SDL_WINDOWPOS_UNDEFINED, width, height,
			 SDL_WINDOW_OPENGL);
    __errorcheck(*windowptr, "initwindow");
}

void
__initrenderer(SDL_Renderer ** rendererptr) {
    *rendererptr = SDL_CreateRenderer(mainwindow, -1,
				      SDL_RENDERER_ACCELERATED
				      | SDL_RENDERER_PRESENTVSYNC);
    __errorcheck(*rendererptr, "renderer");
}

void
__loadimage(SDL_Surface ** imagesurface, const char *restrict file) {
    *imagesurface = NULL;
    *imagesurface = IMG_Load(file);
    __errorcheck(*imagesurface, "loadimage");
}

void
__getwindowsurface(SDL_Window * window, SDL_Surface ** surfaceptr) {
    *surfaceptr = NULL;
    *surfaceptr = SDL_GetWindowSurface(window);
    __errorcheck(*surfaceptr, "getwindowsurface");
}

void
__destroyimage(SDL_Surface ** imagesurfaceptr) {
    __errorcheck(*imagesurfaceptr, "destroyimage");
    SDL_FreeSurface(*imagesurfaceptr);
    *imagesurfaceptr = NULL;
}

void
__destroysurface(SDL_Surface ** surfaceptr) {
    __errorcheck(*surfaceptr, "destroysurface");
    SDL_FreeSurface(*surfaceptr);
    *surfaceptr = NULL;
}

void
__destroyrenderer(SDL_Renderer ** rendererptr) {
    __errorcheck(*rendererptr, "destroyrenderer");
    SDL_DestroyRenderer(*rendererptr);
    *rendererptr = NULL;
}

void
__destroywindow(SDL_Window ** windowptr) {
    __errorcheck(*windowptr, "destroywindow");
    SDL_DestroyWindow(*windowptr);
}

void
__errorcheck(void *object, const char *restrict text) {
    if (object == NULL) {
	perror(text);
	exit(1);
    }
}
