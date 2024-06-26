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
OBJECTS += $(BUILD_DIR)/nh_vector.o

# Pattern rule
$(OBJECTS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Library target
$(BUILD_DIR)/libneushoorn.a: $(OBJECTS)
	ar rcs $@ $^

# Phony targets
.PHONY: clean build

# Phony target: clean
clean:
	rm -rf $(BUILD_DIR)/*

# Phony target: build
build: $(BUILD_DIR)/libneushoorn.a
