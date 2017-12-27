clean :
	rm -rf debug

debug :
	mkdir debug \
&& cd src \
&& gcc -o ../debug/game -g `find . -name "*.c"` -lSDL2 -lSDL2_image -lSDL2_ttf \
&& cd .. \
&& mkdir debug/log \
&& mkdir debug/img \
&& cp `find . -name "*.bmp" -o -name "*.jpg"` debug/img \
&& mkdir debug/sound \
&& mkdir debug/font \
&& cp `find . -name "*.ttf"` debug/font

editinit :
	cd src \
&& emt init.c

redebug :
	make clean \
&& make debug

run :
	make clean \
&& make debug \
&& cd debug \
&& ./game \
&& cd .. 
