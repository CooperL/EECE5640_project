# Simple makefile


CC=mpicc
CFLAGS=-fopenmp -O0 -lm
TARGET=kmeans
OBJ=kmeans 

all:
	$(CC) $(TARGET).c -o $(OBJ) $(CFLAGS)

run: 
	mpirun ./$(TARGET)
