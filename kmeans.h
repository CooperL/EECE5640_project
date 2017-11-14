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
        dist_arry[i][node_idx] = sqrtf(sum);
    }   
}

// scans dist for min and reasigns label based
void find_min_dist(int *labels, float **dist) {
    int i, j;
    for (i = 0; i < N; i++) {
        float curSmall = dist[i][0];
        int small_idx = 0;
        for (j = 1; j < K; j++) {
            if (curSmall > dist[i][j]) {
                curSmall = dist[i][j];
                small_idx = j;
            }
        }
        // relabel point to new cluster
        labels[i] = small_idx;
    }
}

void calc_mean(float** data_arry, int* labels, float** mu) {
    int i,j,m, curLabel;
    for (i = 0; i < K; i++) {
        curLabel = labels[i];
        // zero mean vector so we can use running average
        for (m = 0; m < D; m++)
            mu[i][m] = 0;

        for (j = 0; j < N; j++) 
            if(labels[j] == curLabel) 
                for (m = 0; m < D; m++) 
                    mu[i][m] = (data_arry[j][m] + (m)*mu[i][m])/(m+1);
    }
}

#endif
