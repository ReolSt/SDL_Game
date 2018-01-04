#include "include/library.h"

void
__drawrect(SDL_Renderer * renderer, int size, int xstart, int ystart) {
    SDL_RenderDrawLine(renderer, xstart, ystart, xstart + size, ystart);
    SDL_RenderDrawLine(renderer, xstart + size, ystart, xstart + size,
		       ystart + size);
    SDL_RenderDrawLine(renderer, xstart + size, ystart + size, xstart,
		       ystart + size);
    SDL_RenderDrawLine(renderer, xstart, ystart + size, xstart, ystart);
}
