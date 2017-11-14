#ifndef KMEANS_H
#define KMEANS_H

#include "project.h"
#include <math.h>

void init_mu(float ** data_arry, float*** mu) {
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

void calc_distance(float ** data_arry, float ** mu, float ** dist_arry, int node_idx) {
    int i,j;
    float sum;
    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < D; j++)
            sum += powf((data_arry[i][j] - mu[node_idx][j]),2);
//        dist_arry[i][node_idx] = sqrtf(sum);
    }   
}

#endif
