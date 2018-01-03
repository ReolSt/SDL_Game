clean :
	rm -rf debug

debug :
	mkdir debug \
	&& cd src \
	&& gcc -o ../debug/game -g `find . -name "*.c"` -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer \
	&& cd .. \
	&& mkdir debug/log \
	&& mkdir debug/img \
	&& cp `find . -name "*.png" -o -name "*.jpg"` debug/img \
	&& mkdir debug/sound \
	&& cp `find . -name "*.wav"` debug/sound \
	&& mkdir debug/font \
	&& cp `find . -name "*.ttf"` debug/font

run :
	make clean \
	&& make debug \
	&& cd debug \
	&& ./game \
	&& cd .. 
