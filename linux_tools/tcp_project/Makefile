# Compiler
CC = gcc

# Directories
SRC_DIR = src
BUILD_DIR = build

# Targets
SERVER = $(BUILD_DIR)/server
CLIENT = $(BUILD_DIR)/client

# Source files
SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_SRC = $(SRC_DIR)/client.c

# Default target
all: directories $(SERVER) $(CLIENT)

# Create build directory
directories:
	mkdir -p $(BUILD_DIR)

# Compile server
$(SERVER): $(SERVER_SRC)
	$(CC) $(SERVER_SRC) -o $(SERVER)

# Compile client
$(CLIENT): $(CLIENT_SRC)
	$(CC) $(CLIENT_SRC) -o $(CLIENT)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean directories
