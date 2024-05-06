# Compiler and linker flags
#CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror
CFLAGS = -std=c11 -Wall -Wextra -Werror
CFLAGS += -DDEBUG -ggdb
LDFLAGS = -ffast-math -lm

# Directories
SRC_DIR=src
BUILD_DIR=build
EXT_DIR=ext

# Object files
OBJECTS = $(BUILD_DIR)/nh_logging.o
OBJECTS += $(BUILD_DIR)/nh_arena.o
OBJECTS += $(BUILD_DIR)/nh_window.o

# XDG
OBJECTS += $(BUILD_DIR)/xdg-shell-protocol.o
XDG_ITEMS = $(SRC_DIR)/xdg-shell-protocol.c
XDG_ITEMS += $(SRC_DIR)/xdg-shell-protocol.h

# Pattern rule
$(OBJECTS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(XDG_ITEMS)
	$(CC) $(CFLAGS) -c $< -o $@

# XDG source file
$(SRC_DIR)/xdg-shell-protocol.c:
	wayland-scanner private-code \
		/usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml $@
# XDG header file
$(SRC_DIR)/xdg-shell-protocol.h:
	wayland-scanner client-header \
		/usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml $@

# Library target
$(BUILD_DIR)/libneushoorn.a: $(OBJECTS)
	ar rcs $@ $^

# Phony targets
.PHONY: clean build

# Phony target: clean
clean:
	rm -rf $(BUILD_DIR)/*
	rm -rf $(SRC_DIR)/xdg-shell-*

# Phony target: build
build: $(BUILD_DIR)/libneushoorn.a
