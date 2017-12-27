#include "include/init.h"
#include "include/handle.h"
#include "include/print.h"
#include "include/menu.h"

int             width = 1280;
int             height = 720;

SDL_Window     *mainwindow;
SDL_Renderer   *renderer;
SDL_Event       event;
SDL_Event       gameevent;
SDL_Surface    *mainwindowsurface;
SDL_Surface    *startimgsurface;
SDL_Surface    *mainmenusurface;
SDL_Surface    *gameimgsurface;
TTF_Font       *menuttf;	// default

SDL_Color       black = { 0, 0, 0, 255 };
SDL_Color       white = { 255, 255, 255, 255 };
SDL_Color       red = { 255, 0, 0, 255 };
SDL_Color       green = { 0, 255, 0, 255 };
SDL_Color       blue = { 0, 0, 255, 255 };

SDL_Rect        mainmenurect = { 1280 / 2, 720 / 2, 0, 0 };
SDL_Rect        mainmenurect2 = { 1280 / 2, 720 / 2 + 20, 0, 0 };
// handler
__flags         mainflags = { 0, 0, 0 };
__flags         gameflags = { 0, 0, 0 };

int
main(int __attribute__ ((unused)) argc, char **
     __attribute__ ((unused)) argv) {

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    __initwindow(&mainwindow, "debug");
    __initrenderer(&renderer);
    __inithandler(&mainflags);
    __initprinter();

    __getwindowsurface(mainwindow, &mainwindowsurface);
    __loadttf(&menuttf, "font/LM-Regular.ttf", 20);

    mainmenusurface =
	TTF_RenderText_Shaded(menuttf, "hello", white, black);

    while (mainflags.running) {
	if (!mainflags.init) {
	    __loadimage(&startimgsurface, "img/main.jpg");
	    SDL_BlitSurface(startimgsurface, NULL, mainwindowsurface,
			    NULL);
	    SDL_BlitSurface(mainmenusurface, NULL, mainwindowsurface,
			    &mainmenurect);
	    mainmenusurface =
		TTF_RenderText_Shaded(menuttf, "world", white, black);
	    SDL_BlitSurface(mainmenusurface, NULL, mainwindowsurface,
			    &mainmenurect2);
	    mainflags.init = 1;
	}

	while (SDL_PollEvent(&event)) {
	    __handleevent(&event, &mainflags);
	}

	SDL_UpdateWindowSurface(mainwindow);
    }

    __destroyttf(&menuttf);
    __destroyimage(&startimgsurface);
    __destroysurface(&mainwindowsurface);
    __destroywindow(&mainwindow);
    __destroyrenderer(&renderer);
    __destroyprinter();
    TTF_Quit();
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
    *rendererptr = NULL;
    *rendererptr = SDL_CreateRenderer(mainwindow, -1,
				      SDL_RENDERER_ACCELERATED);
    __errorcheck(*rendererptr, "renderer");
}

void
__loadimage(SDL_Surface ** imagesurface, const char *restrict file) {
    *imagesurface = NULL;
    *imagesurface = IMG_Load(file);
    __errorcheck(*imagesurface, "loadimage");
}

void
__loadttf(TTF_Font ** fontptr, const char *restrict file, int size) {
    *fontptr = NULL;
    *fontptr = TTF_OpenFont(file, size);
    __errorcheck(*fontptr, "loadttf");
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
__destroyttf(TTF_Font ** fontptr) {
    __errorcheck(*fontptr, "destroyttf");
    TTF_CloseFont(*fontptr);
}

void
__errorcheck(void *object, const char *restrict text) {
    if (object == NULL) {
	perror(text);
	exit(1);
    }
}
