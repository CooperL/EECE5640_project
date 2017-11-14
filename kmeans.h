#ifndef KMEANS_H
#define KMEANS_H

#include <stdlib.h>

void init_mu(float ** data_arry, float*** mu, int N, int D, int K) {
    *mu = malloc(K*sizeof(float*));
    int i,j;
    for (i = 0; i < N; i++)
        (*mu)[i] = malloc(D*sizeof(float));

    // pick random index from data
    int idx;
    srand(1);
    for (i = 0; i < K; i++) {
        idx = rand()%N;
        for (j = 0; j < D; j++)
            (*mu)[i][j] = data_arry[idx][j]; 
    }
}

#endif
