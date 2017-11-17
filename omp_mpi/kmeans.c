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

    int taskid, numtasks;

    // split into k nodes
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &taskid);

    int num_iterations = 0;
    int not_done = 0;
    do {
        // calculate distance in each row
        //for(taskid = 0; taskid < K; taskid++)
        calc_distance(data_arry,mu,dist,taskid);
       
        // Send distances back to captain node
        if (taskid != MASTER) {
            MPI_Send(dist[taskid], N, MPI_FLOAT, MASTER, taskid, MPI_COMM_WORLD );
        }
        else {
            // because MASTER is 0
            for (i = 1; i < K; i++)
                MPI_Recv(dist[i], N, MPI_FLOAT, i, i, MPI_COMM_WORLD, &status );
        }

        if (taskid == MASTER) {
            // select minimum distance and assign new label
            find_min_dist(labels, dist);
    
            // update mean
            copy_mu(mu, mu_prev);
            calc_mean(data_arry, labels, mu);
    
            // Send updated means back to nodes
            for (i = 1; i < K; i++)
                MPI_Send(mu[i], D, MPI_FLOAT, i, i, MPI_COMM_WORLD);
        
            num_iterations++;

            not_done = num_iterations < MAX_ITERATIONS && comp_dmu(mu, mu_prev);
        }
        else {
            MPI_Recv(mu[taskid], D, MPI_FLOAT, MASTER, taskid, MPI_COMM_WORLD, &status);
        }

        if (taskid == MASTER) {
            for(i = 1; i < K; i++)
                MPI_Send(mu_prev[i], D, MPI_FLOAT, i, i, MPI_COMM_WORLD);
        }
        else {
            MPI_Recv(mu_prev[taskid], D, MPI_FLOAT, MASTER, taskid, MPI_COMM_WORLD, &status);
        }
  
        MPI_Bcast(&not_done, 1, MPI_INT, MASTER, MPI_COMM_WORLD);  
    }
    while (not_done);

    MPI_Finalize();

    // force all other processes to return so they don't 
    // write to output.csv
    if (taskid != MASTER)
        return 0;

    stop = CLOCK();
    printf("num_iterations: %d\n",num_iterations);
 
    total_time = stop - start;
    printf("total compute time: %f\n", total_time);

    // write results to .csv
    FILE* output_fp = fopen(OUTPUT_FILE,"w");
    write_csv(output_fp, labels);
    fclose(output_fp);

    // clean up
    free_matrix(&data_arry, N);
    free_matrix(&dist, K);
    free_matrix(&mu, K);
    free_matrix(&mu_prev, K);
    free(labels);
}
