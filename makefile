.PHONY: build test clean

clean:
	rm -rf build/*

build:
	cd build    \
	&& cmake .. \
	&& make

test:
	cd build    \
	&& cmake .. \
	&& make     \
	&& ./nh_test
	make clean
