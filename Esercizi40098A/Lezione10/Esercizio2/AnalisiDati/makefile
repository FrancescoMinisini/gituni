# Variabili
CC = g++
CFLAGS = -Wall
RFLAGS = $(shell root-config --cflags --libs)
SRC = main.cpp
OBJ_DIR = objs
OBJ = $(OBJ_DIR)/main.o
HEADERS = $(wildcard ../Models/*.h)

# Regola principale
all: main

# Compilazione dell'eseguibile
main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(RFLAGS)

# Compilazione dei file .o
$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia
clean:
	rm -rf $(OBJ_DIR) main
