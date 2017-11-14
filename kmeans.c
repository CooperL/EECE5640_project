#include <stdio.h>
#include "data.h"
#include "kmeans.h"

#define N 10000
#define D 10
#define K 3
#define DATA_FILE "samples.csv"
#define LABEL_FILE "clusters.csv"

int main(int argc, char* argv[]) {
    int i,j;
    float** data_arry;
    init_data(&data_arry,N,D);
    int* labels = (int*)malloc(N*sizeof(int));
    float ** mu;
    FILE* data_fp = fopen(DATA_FILE,"r");

    read_csv(data_fp, data_arry, N, D);
    //print_data(data_arry,N,D);
    
    // select initial means
    init_mu(data_arry, &mu, N, D, K);
    
    // split onto k nodes... later

    // find mean
    //calc_mean(data_arry, labels, mu,N,D);
    // calculate distance in each row
    calc_distance(data_arry,mu,N,D );
    
    free_data(&data_arry,N,D);
}
