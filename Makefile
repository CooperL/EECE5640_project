# Simple makefile


CC=gcc
CFLAGS=
TARGET=kmeans.c
OBJ=kmeans 

all:
	$(CC) $(CFLAGS) $(TARGET) -o $(OBJ)
