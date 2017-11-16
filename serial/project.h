#ifndef PROJECT_H
#define PROJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define D 3
#define K 3
#define DATA_FILE "samples.csv"
#define LABEL_FILE "clusters.csv"
#define OUTPUT_FILE "output.csv"
#define MAX_ITERATIONS 20
#define THRESHOLD 0.01

double CLOCK() {
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return (t.tv_sec * 1000)+(t.tv_nsec * 1e-6);
}

#endif