#include "include/library.h"

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
__destroytexture(SDL_Texture ** textureptr) {
    __errorcheck(textureptr, "destroytexture");
    SDL_DestroyTexture(*textureptr);
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
