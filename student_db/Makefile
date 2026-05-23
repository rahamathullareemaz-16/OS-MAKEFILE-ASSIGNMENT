CC = gcc

DEBUG_FLAGS = -g -Wall
RELEASE_FLAGS = -O2 -Wall

MODE ?= DEBUG

ifeq ($(MODE),DEBUG)
    CFLAGS = $(DEBUG_FLAGS)
else
    CFLAGS = $(RELEASE_FLAGS)
endif

INCLUDE = -Iinclude

SRC_DIR = src
APP_DIR = apps
BUILD_DIR = build
BIN_DIR = bin

COMMON_SRC = $(wildcard $(SRC_DIR)/*.c)
COMMON_OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(COMMON_SRC))

ADD_MAIN = $(APP_DIR)/add_main.c
SEARCH_MAIN = $(APP_DIR)/search_main.c
DISPLAY_MAIN = $(APP_DIR)/display_main.c

ADD_EXE = $(BIN_DIR)/add_student
SEARCH_EXE = $(BIN_DIR)/search_student
DISPLAY_EXE = $(BIN_DIR)/display_student

DEP = $(COMMON_OBJ:.o=.d)

all: directories $(ADD_EXE) $(SEARCH_EXE) $(DISPLAY_EXE)

directories:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BIN_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -c $< -o $@

$(ADD_EXE): $(COMMON_OBJ) $(ADD_MAIN)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

$(SEARCH_EXE): $(COMMON_OBJ) $(SEARCH_MAIN)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

$(DISPLAY_EXE): $(COMMON_OBJ) $(DISPLAY_MAIN)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

run:
	./bin/display_student

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

-include $(DEP)
