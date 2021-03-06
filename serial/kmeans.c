/***************************************************
*  kmeans.c
*  
*  Compute kmeans for samples.csv
*  labels are placed in output.csv
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
    float** mu_prev;
    init_mu_prev(&mu_prev);
    float** dist;
    init_dist(&dist);

    double start, stop, total_time;
    
    FILE* data_fp = fopen(DATA_FILE,"r");
    read_csv(data_fp, data_arry);
    fclose(data_fp);
    //print_data(data_arry);
    
    start = CLOCK();

    int num_iterations = 0;
    do {
        // split onto k nodes... later

        // calculate distance in each row
        int node_idx;
        for(node_idx = 0; node_idx < K; node_idx++)
            calc_distance(data_arry,mu,dist,node_idx);

        // TODO: MPI Reduce

        // select minimum distance and assign new label
        find_min_dist(labels, dist);
    
        // update mean
        copy_mu(mu, mu_prev);
        calc_mean(data_arry, labels, mu);
    
        num_iterations++;
    }
    while (num_iterations < MAX_ITERATIONS && comp_dmu(mu, mu_prev));
   
    stop = CLOCK();
    printf("num_iterations: %d\n",num_iterations);
 
    total_time = stop - start;
    printf("total time: %f\n", total_time);

    // write results to .csv
    FILE* output_fp = fopen(OUTPUT_FILE,"w");
    write_csv(output_fp, labels);
    fclose(output_fp);

    // clean up
    free_matrix(&data_arry, N);
    free_matrix(&dist, N);
    free_matrix(&mu, K);
    free_matrix(&mu_prev, K);
    free(labels);
}
