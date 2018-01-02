#include "include/library.h"

void
__drag(SDL_MouseMotionEvent * motion, SDL_Rect * rect) {
    if (motion->state == 1) {
	if (motion->x > rect->x && motion->x < rect->x + rect->w) {
	    if (motion->y > rect->y && motion->y < rect->y + rect->h) {
		rect->x = motion->x - rect->w / 2;
		rect->y = motion->y - rect->h / 2;
	    }
	}
    }
}
