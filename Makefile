CC = g++
CFLAGS = -std=c++11 -Wall

SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

all: $(BIN_DIR)/tp2.out

$(OBJ_DIR)/Nos.o: $(INCLUDE_DIR)/Nos.hpp $(SRC_DIR)/Nos.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Nos.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Nos.o

$(OBJ_DIR)/ListaEncadeada.o: $(INCLUDE_DIR)/Nos.hpp $(INCLUDE_DIR)/ListaEncadeada.hpp $(SRC_DIR)/ListaEncadeada.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ListaEncadeada.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/ListaEncadeada.o

$(OBJ_DIR)/Pilha.o: $(INCLUDE_DIR)/Nos.hpp $(INCLUDE_DIR)/Pilha.hpp $(SRC_DIR)/Pilha.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Pilha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Pilha.o

$(OBJ_DIR)/Fila.o: $(INCLUDE_DIR)/Nos.hpp $(INCLUDE_DIR)/Fila.hpp $(SRC_DIR)/Fila.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Fila.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Fila.o

$(OBJ_DIR)/Pacote.o: $(INCLUDE_DIR)/Pacote.hpp $(SRC_DIR)/Pacote.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Pacote.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Pacote.o

$(OBJ_DIR)/Evento.o: $(INCLUDE_DIR)/Pacote.hpp $(INCLUDE_DIR)/Evento.hpp $(SRC_DIR)/Evento.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Evento.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Evento.o

$(OBJ_DIR)/Escalonador.o: $(INCLUDE_DIR)/Evento.hpp $(INCLUDE_DIR)/Escalonador.hpp $(SRC_DIR)/Escalonador.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Escalonador.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Escalonador.o

$(OBJ_DIR)/Armazem.o: $(INCLUDE_DIR)/Pilha.hpp $(INCLUDE_DIR)/ListaEncadeada.hpp $(INCLUDE_DIR)/Armazem.hpp $(SRC_DIR)/Armazem.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Armazem.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Armazem.o

$(OBJ_DIR)/Grafo.o: $(INCLUDE_DIR)/Armazem.hpp $(INCLUDE_DIR)/Grafo.hpp $(SRC_DIR)/Grafo.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Grafo.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Grafo.o

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/Grafo.hpp $(INCLUDE_DIR)/Escalonador.hpp $(INCLUDE_DIR)/Fila.hpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o


$(BIN_DIR)/tp2.out: \
	$(OBJ_DIR)/Armazem.o \
	$(OBJ_DIR)/Escalonador.o \
	$(OBJ_DIR)/Evento.o \
	$(OBJ_DIR)/Grafo.o \
	$(OBJ_DIR)/ListaEncadeada.o \
	$(OBJ_DIR)/main.o \
	$(OBJ_DIR)/Nos.o \
	$(OBJ_DIR)/Pacote.o \
	$(OBJ_DIR)/Fila.o \
	$(OBJ_DIR)/Pilha.o
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/tp2.out
