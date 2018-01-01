#include "include/library.h"

int             width = 1280;
int             height = 720;

SDL_Window     *mainwindow;
SDL_Renderer   *renderer;
SDL_Event       event;

SDL_Texture    *startimgtexture;
SDL_Texture    *mainmenutexture;
SDL_Texture    *junkrat;
SDL_Texture    *mercy;

SDL_Texture    *glow;

TTF_Font       *menuttf;

SDL_Color       black = { 0, 0, 0, 255 };
SDL_Color       white = { 255, 255, 255, 255 };
SDL_Color       red = { 255, 0, 0, 255 };
SDL_Color       green = { 0, 255, 0, 255 };
SDL_Color       blue = { 0, 0, 255, 255 };

SDL_Rect        mainmenurect = { 100, 400, 0, 0 };
SDL_Rect        characterrect = { 640, 360, 128, 128 };

SDL_Point       flippoint = { 64, 64 };

// handler
__flags         mainflags = { 0, 0, 0, 0, 0, 1, 0, 0 };

int
main(int __attribute__ ((unused)) argc, char **
     __attribute__ ((unused)) argv) {
  mainloop:
    while (mainflags.running) {

	while (SDL_PollEvent(&event)) {
	    __handleevent(&event, &mainflags);
	}
	
	SDL_RenderClear(renderer);
	SDL_SetWindowFullscreen(mainwindow, SDL_WINDOW_FULLSCREEN);

	// SDL_RenderCopy(renderer, startimgtexture, NULL, NULL);
	SDL_RenderCopy(renderer, junkrat, NULL, &characterrect);
	
	if(mainflags.movex==1 || mainflags.movex==-1) {
	    characterrect.x+=mainflags.movex*20;
	    mainflags.movex=0;
	}
	
	if(mainflags.movey==1 || mainflags.movey==-1) {
	    characterrect.y+=mainflags.movey*20;
	    mainflags.movey=0;
	}
	
	if(mainflags.mousemotion) {
	    	characterrect.x+=mainflags.xrel;
         	characterrect.y+=mainflags.yrel;
		SDL_WarpMouseGlobal(640, 360);
	}

	SDL_RenderPresent(renderer);
	SDL_Delay(10);
    }

    if (!mainflags.init) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_JPG);
	SDL_ShowCursor(SDL_DISABLE);
	__initwindow(&mainwindow, "debug");
	__initrenderer(&renderer);
	__inithandler(&mainflags);
	__initprinter();

	__loadttf(&menuttf, "font/LM-Regular.ttf", 20);

	startimgtexture = IMG_LoadTexture(renderer, "img/main.jpg");
	junkrat = IMG_LoadTexture(renderer, "img/junkrat.jpg");

	mainflags.init = 1;
	goto mainloop;
    }

    __destroyttf(&menuttf);
    __destroytexture(&startimgtexture);
    __destroytexture(&junkrat);
    __destroywindow(&mainwindow);
    __destroyrenderer(&renderer);
    __destroyprinter();
    TTF_Quit();
    IMG_Quit();
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
__loadimage(SDL_Texture ** imagetexture, SDL_Renderer * renderer,
	    const char *restrict filename) {
    SDL_Surface    *dummysurface = NULL;
    dummysurface = IMG_Load(filename);
    *imagetexture = SDL_CreateTextureFromSurface(renderer, dummysurface);
    SDL_FreeSurface(dummysurface);
}

void
__loadttf(TTF_Font ** fontptr, const char *restrict filename, int size) {
    *fontptr = NULL;
    *fontptr = TTF_OpenFont(filename, size);
    __errorcheck(*fontptr, "loadttf");
}

void
__getwindowsurface(SDL_Window * window, SDL_Surface ** surfaceptr) {
    *surfaceptr = NULL;
    *surfaceptr = SDL_GetWindowSurface(window);
    __errorcheck(*surfaceptr, "getwindowsurface");
}
