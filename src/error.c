#include "include/library.h"

void
__errorcheck(void *object, const char *restrict text) {
    if (object == NULL) {
	perror(text);
	exit(1);
    }
}
