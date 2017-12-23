#ifndef __MENU_H
#define __MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "color.h"

typedef struct {
    __color         textcolor;
    char           *text;
} __menu_item;

typedef struct {
    __color         menucolor;
    TTF_Font       *font;
    __menu_item    *mobj;
} __menu;

__menu          mainmenu;
__menu_item    *mobj;
__color         mainmenucolor;

#endif
