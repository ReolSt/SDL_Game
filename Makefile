clean :
	rm -rf debug

debug :
	mkdir debug && cd src && gcc -o ../debug/test -g `find . -name "*.c"` -lSDL2 -lSDL2_image && cd .. && mkdir debug/log && mkdir debug/img && cp `find . -name "*.bmp" -o -name "*.jpg"` debug/img

editinit :
	cd src && emt init.c
