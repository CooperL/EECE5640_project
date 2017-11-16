# Simple makefile


CC=mpicc
CFLAGS=-fopenmp -O0 -lm
TARGET=kmeans
OBJ=kmeans
K=3

all:
	$(CC) $(TARGET).c -o $(OBJ) $(CFLAGS)

run: 
	mpirun -np $(K) -prot -TCP ./$(TARGET)
