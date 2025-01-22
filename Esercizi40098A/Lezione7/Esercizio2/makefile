# Variabili
CC = g++
CFLAGS = -Wall -std=c++17
ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --libs)
ARMADILLOFLAGS = $(shell pkg-config --cflags armadillo)
ARMADILLOLIBS = $(shell pkg-config --libs armadillo)

SRC = main.cpp
OBJ_DIR = objs
OBJ = $(OBJ_DIR)/main.o
HEADERS = $(wildcard Models/*.h)

# Regola principale
all: Esercizio3

# Compilazione dell'eseguibile
Esercizio3: $(OBJ)
	$(CC) $(CFLAGS) $(ROOTFLAGS) $(ARMADILLOFLAGS) -o $@ $^ $(ROOTLIBS) $(ARMADILLOLIBS)

# Compilazione dei file .o
$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(ROOTFLAGS) $(ARMADILLOFLAGS) -c $< -o $@

# Pulizia
clean:
	rm -rf $(OBJ_DIR) Esercizio3
