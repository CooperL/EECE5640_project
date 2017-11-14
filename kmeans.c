/***************************************************
*  kmeans.c
*  
*  Compute kmeans for samples.csv
*  labels are placed in label_out.csv
*
*  Final project for EECE5640
*
*  @author Cooper Loughlin
*  @autor Brian Yarbrough
*  @date November 2017
*
****************************************************/


#include "project.h"
#include "data.h"
#include "kmeans.h"


int main(int argc, char* argv[]) {
    int i,j;
    float** data_arry;
    init_data(&data_arry);
    int* labels = (int*)malloc(N*sizeof(int));
    float** mu;
    init_mu(data_arry, &mu);
    float** dist;
    init_dist(&dist);
    FILE* data_fp = fopen(DATA_FILE,"r");

    read_csv(data_fp, data_arry);
    //print_data(data_arry);
    
    // split onto k nodes... later

    // calculate distance in each row
    int node_idx;
    for(node_idx = 0; node_idx < K; node_idx++)
        calc_distance(data_arry,mu,dist,node_idx);

    // TODO: MPI Reduce

    // select minimum distance
    find_min_dist(labels, dist);
    
    // update mean
    calc_mean(data_arry, labels, mu);

    for(i=0;i<D;i++)
        printf("%f ",mu[K][i]);
    printf("\n");

    // clean up
    free(mu[0]);
    /*    
    free_matrix(&data_arry, N);
    free_matrix(&dist, N);
    //free_matrix(&mu, K);
    free(labels);*/
}
