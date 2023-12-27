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
	echo "	+-> base.c done."
	gcc -c $(SRC_DIR)/arena_alloc.c $(CFLAGS) -o $(BUILD_DIR)/arena_alloc.o
	echo "	+-> arena_alloc.c done."
	gcc -c $(SRC_DIR)/logging.c $(CFLAGS) -o $(BUILD_DIR)/logging.o
	echo "	+-> logging.c done."
	gcc -c $(SRC_DIR)/file_io.c $(CFLAGS) -o $(BUILD_DIR)/file_io.o
	echo "	+-> file_io.c done."
	echo "Archiving..."
	ar rcs $(BUILD_DIR)/libneushoorn.a $(BUILD_DIR)/*.o
	echo "Copying files..."
	rm -rf /usr/include/neushoorn/*
	cp $(SRC_DIR)/*.h /usr/include/neushoorn/
	cp $(BUILD_DIR)/*.a /usr/lib/x86_64-linux-gnu/
	echo "Done!"

test:
	gcc $(TEST_DIR)/main.c -o $(BUILD_DIR)/test -lneushoorn -lm -DDEBUG
	$(BUILD_DIR)/test
	rm -rf $(BUILD_DIR)/test

# Should use corefiles - I can't change my corepattern on WSL2 though
gdb:
	gcc -g $(TEST_DIR)/main.c -o $(BUILD_DIR)/test_gdb -lneushoorn -lm -DDEBUG
	gdb $(BUILD_DIR)/test_gdb
