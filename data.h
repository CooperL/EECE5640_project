#ifndef DATA_H
#define DATA_H

#include "project.h"

// FUNCTIONS
void init_data(float*** data_arry) {
    *data_arry = (float**) malloc(N*sizeof(float*));
    int i;
    for(i=0;i<N;i++)
        (*data_arry)[i] = (float*) malloc(D*sizeof(float));
}

void free_matrix(float*** data_arry, int L) {
    int i;
    for(i=0;i<L;i++)
        free((*data_arry)[i]);
    free(*data_arry);
}

void print_data(float** data_arry) {
    printf("in print\n");
    int i,j;
    for(i=0;i<N;i++) {
        for(j=0;j<D;j++)
            printf("%f ",data_arry[i][j]);
        printf("\n");
    }
}

void read_csv(FILE* data_file, float** data_arry) {
    
    int i,j;
    for(i=0;i<N;i++) {
        for(j=0;j<D;j++) {
            fscanf(data_file,"%f,",&(data_arry[i][j]));
        }
    }
 
}

void init_dist(float*** dist_arry) {
    *dist_arry = malloc(N*sizeof(float*));
    int i;
    for(i=0;i<N;i++)
        (*dist_arry)[i] = malloc(K*sizeof(float));
}
 
#endif
