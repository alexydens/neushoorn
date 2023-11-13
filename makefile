BUILD_DIR=build
TEST_DIR=test
SRC_DIR=src

CFLAGS = -ansi -pedantic -Wall -Wextra -Wno-unused-variable

.PHONY: build clean test gdb
.SILENT: build

clean:
	rm -rf $(BUILD_DIR)/*

build:
	echo "Compiling to object files..."
	gcc -c $(SRC_DIR)/base.c $(CFLAGS) -o $(BUILD_DIR)/base.o
	gcc -c $(SRC_DIR)/arena_alloc.c $(CFLAGS) -o $(BUILD_DIR)/arena_alloc.o
	gcc -c $(SRC_DIR)/logging.c $(CFLAGS) -o $(BUILD_DIR)/logging.o
	gcc -c $(SRC_DIR)/file_io.c $(CFLAGS) -o $(BUILD_DIR)/file_io.o
	gcc -c $(SRC_DIR)/window.c $(CFLAGS) -o $(BUILD_DIR)/window.o
	gcc -c $(SRC_DIR)/shader.c $(CFLAGS) -o $(BUILD_DIR)/shader.o
	gcc -c $(SRC_DIR)/texture.c $(CFLAGS) -o $(BUILD_DIR)/texture.o
	gcc -c $(SRC_DIR)/mesh.c $(CFLAGS) -o $(BUILD_DIR)/mesh.o
	echo "Archiving..."
	ar rcs $(BUILD_DIR)/libneushoorn.a $(BUILD_DIR)/*.o
	echo "Copying files..."
	cp $(SRC_DIR)/*.h /usr/include/neushoorn/
	cp $(BUILD_DIR)/*.a /usr/lib/x86_64-linux-gnu/
	echo "Done!"

test:
	gcc $(TEST_DIR)/main.c -o $(BUILD_DIR)/test -lneushoorn -lm -lSDL2 -lGL
	$(BUILD_DIR)/test
	rm -rf $(BUILD_DIR)/test

# If anyone is going to use this, feel free to add corefiles to the mix - it
# just doesn't work for me on WSL2
gdb:
	gcc -g $(TEST_DIR)/main.c -o $(BUILD_DIR)/test_gdb -lSDL2 -lSDL2_image -lneushoorn -lm -lGL
	gdb $(BUILD_DIR)/test_gdb
