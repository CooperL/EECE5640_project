# Simple makefile


CC=gcc
CFLAGS= -fopenmp -lm
TARGET=kmeans.c
OBJ=kmeans 

all:
	$(CC) $(TARGET) -o $(OBJ) $(CFLAGS)
