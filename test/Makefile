all:
	gcc main.c ../build/libneushoorn.a -DDEBUG -ggdb -lwayland-client -lvulkan
	WAYLAND_DEBUG=1 ./a.out
	#./a.out
