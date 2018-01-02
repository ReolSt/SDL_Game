#include "include/library.h"

int             width = 800;
int             height = 600;

SDL_Window     *mainwindow;
SDL_Renderer   *renderer;
SDL_Event       event;

SDL_KeyboardEvent *keyboardevent;
SDL_MouseMotionEvent *motionevent;
SDL_MouseButtonEvent *buttonevent;

SDL_Texture    *startimgtexture;
SDL_Texture    *mainmenutexture;
SDL_Texture    *junkrat;
SDL_Texture    *mercy;
SDL_Texture    *hanzo;
SDL_Texture    *lucio;
SDL_Texture    *zenyatta;

TTF_Font       *menuttf;

SDL_Color       black = { 0, 0, 0, 255 };
SDL_Color       white = { 255, 255, 255, 255 };
SDL_Color       red = { 255, 0, 0, 255 };
SDL_Color       green = { 0, 255, 0, 255 };
SDL_Color       blue = { 0, 0, 255, 255 };

SDL_Rect        mainmenurect = { 100, 400, 0, 0 };
SDL_Rect        junkratrect = { 0, 0, 64, 64 };
SDL_Rect        mercyrect = { 0, 0, 64, 64 };
SDL_Rect hanzorect = { 0, 0, 64, 64 };
SDL_Rect luciorect = { 0, 0, 64, 64 };
SDL_Rect zenyattarect = {0, 0, 64, 64};

__flags         mainflags = { 0, 0 };

int
main(int __attribute__ ((unused)) argc, char **
     __attribute__ ((unused)) argv) {
  mainloop:
    while (mainflags.running) {

	while (SDL_PollEvent(&event)) {
	    __printlog("\n");
	    switch (event.type) {
	    case SDL_KEYDOWN:
		__handlekey(&event, &mainflags, &(event.key));
		break;
	    case SDL_MOUSEBUTTONDOWN:
		__printmousebutton(&event, &(event.button));
		break;
	    case SDL_MOUSEMOTION:
		__printmousemotion(&event, &(event.motion));
		break;
	    case SDL_QUIT:
		__printquit(&event);
		__handlequit(&event, &mainflags);
		break;
	    default:
		break;
	    }	    
	}

		__drag(motionevent, &junkratrect);
         	__drag(motionevent, &mercyrect);
		__drag(motionevent, &hanzorect);
		__drag(motionevent, &luciorect);
		__drag(motionevent, &zenyattarect);

	// SDL_SetWindowFullscreen(mainwindow, SDL_WINDOW_FULLSCREEN);

	SDL_RenderClear(renderer);

	// SDL_RenderCopy(renderer, startimgtexture, NULL, NULL);
	SDL_RenderCopy(renderer, junkrat, NULL, &junkratrect);
	SDL_RenderCopy(renderer, mercy, NULL, &mercyrect);
	SDL_RenderCopy(renderer, hanzo, NULL, &hanzorect);
	SDL_RenderCopy(renderer, lucio, NULL, &luciorect);
	SDL_RenderCopy(renderer, zenyatta, NULL, &zenyattarect);

	SDL_RenderPresent(renderer);
	SDL_Delay(10);
    }

    if (!mainflags.init) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_JPG);
	
	__initwindow(&mainwindow, "debug");
	__initrenderer(&renderer);
	__inithandler(&mainflags);
	__initprinter();

	srand(time(NULL));

	keyboardevent = &event.key;
	buttonevent = &event.button;
	motionevent = &event.motion;


	__loadttf(&menuttf, "font/LM-Regular.ttf", 20);

	startimgtexture = IMG_LoadTexture(renderer, "img/main.jpg");
	junkrat = IMG_LoadTexture(renderer, "img/junkrat.jpg");
	mercy = IMG_LoadTexture(renderer, "img/mercy.jpg");
	hanzo = IMG_LoadTexture(renderer, "img/hanzo.jpg");
	lucio = IMG_LoadTexture(renderer, "img/lucio.jpg");
	zenyatta = IMG_LoadTexture(renderer, "img/zenyatta.jpg");

	junkratrect.x = rand() % width;
	junkratrect.y = rand() % height;
	mercyrect.x = rand() % width;
	mercyrect.y = rand() % height;
	hanzorect.x = rand() % width;
	hanzorect.y = rand() % height;
	luciorect.x = rand() % width;
	luciorect.y = rand() % height;
	zenyattarect.x = rand() % width;
	zenyattarect.y = rand() % height;
        

	mainflags.init = 1;
	goto mainloop;
    }

    __destroyttf(&menuttf);
    
    __destroytexture(&startimgtexture);
    __destroytexture(&junkrat);
    __destroytexture(&mercy);
    __destroytexture(&hanzo);
    __destroytexture(&lucio);
    __destroytexture(&zenyatta);
    
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
__loadimage(SDL_Texture ** imgtexture, SDL_Renderer * renderer,
	    const char *restrict filename) {
    SDL_Surface    *dummysurface = NULL;
    dummysurface = IMG_Load(filename);
    __errorcheck(dummysurface, "loadimage_IMG_Load");
    *imgtexture = SDL_CreateTextureFromSurface(renderer, dummysurface);
    SDL_FreeSurface(dummysurface);
    __errorcheck(*imgtexture, "loadimage");
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
