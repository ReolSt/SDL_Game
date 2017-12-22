clean :
	rm -rf debug

debug :
	mkdir debug && cd src && gcc -o ../debug/test -g `find . -name "*.c"` -lSDL2 && cd .. && mkdir debug/log && mkdir debug/img && cp src/img/main.bmp debug/img
