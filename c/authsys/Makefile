# Executables
RDB = rdb
IMC = imc
IPC = ipc

# Compile
CC = gcc
FLAGS = -Wall -Werror -std=gnu11
SQLITE = -lpthread -ldl -lm

# Folder
SRC = src
BIN = bin
LIB = libs

.PHONY: all clean 

all: $(RDB) $(IMC) $(IPC)

clean:
	rm -rf $(BIN)/*.o $(BIN)/$(RDB) $(BIN)/$(IMC) $(BIN)/$(IPC)

astp.o: astp.c
	$(CC) -c -o $(BIN)/astp.o $(SRC)/astp.c

sqlite3.o: $(LIB)/sqlite3.c
	$(CC) -c -o $(BIN)/sqlite3.o $(LIB)/sqlite3.c

shell.o: $(LIB)/shell.c
	$(CC) -c -o $(BIN)/shell.o $(LIB)/shell.c

rdb.o: rdb.c
	$(CC) -c -o $(BIN)/rdb.o $(SRC)/rdb.c

imc.o: imc.c
	$(CC) -c -o $(BIN)/imc.o $(SRC)/imc.c

ipc.o: ipc.c
	$(CC) -c -o $(BIN)/ipc.o $(SRC)/ipc.c

$(RDB): astp.o sqlite.o rdb.o
	$(CC) $(FLAGS) $(SQLITE) -o $(BIN)/$(RDB) $(BIN)/astp.o $(BIN)/sqlite.o $(BIN)/rdb.o 

$(IMC): astp.o imc.o
	$(CC) $(FLAGS) -o $(BIN)/$(IMC) $(BIN/)astp.o $(BIN)/imc.o 

$(IPC): astp.o ipc.o
	$(CC) $(FLAGS) -o $(BIN)/$(IPC) $(BIN)/astp.o $(BIN)/ipc.o 

