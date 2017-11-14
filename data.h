#ifndef DATA_H
#define DATA_H

#include <stdlib.h>

// FUNCTIONS
void init_data(float*** data_arry, int N, int D) {
    *data_arry = malloc(N*sizeof(float*));
    int i;
    for(i=0;i<N;i++)
        (*data_arry)[i] = malloc(D*sizeof(float));
}

void free_data(float*** data_arry, int N, int D) {
    int i;
    for(i=0;i<N;i++)
        free((*data_arry)[i]);
    free(*data_arry);
}

void print_data(float** data_arry, int N, int D) {
    printf("in print\n");
    int i,j;
    for(i=0;i<N;i++) {
        for(j=0;j<D;j++)
            printf("%f ",data_arry[i][j]);
        printf("\n");
    }
}

void read_csv(FILE* data_file, 
              float** data_arry, 
              int N, int D) {
    
    int i,j;
    for(i=0;i<N;i++) {
        for(j=0;j<D;j++) {
            fscanf(data_file,"%f,",&(data_arry[i][j]));
        }
    }
 
} 
#endif
