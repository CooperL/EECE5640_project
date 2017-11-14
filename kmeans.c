#include "project.h"
#include "data.h"
#include "kmeans.h"


int main(int argc, char* argv[]) {
    int i,j;
    float** data_arry;
    init_data(&data_arry);
    int* labels = (int*)malloc(N*sizeof(int));
    float ** mu;
    float ** dist;
    init_dist(&dist);
    FILE* data_fp = fopen(DATA_FILE,"r");

    read_csv(data_fp, data_arry);
    //print_data(data_arry);
    
    // select initial means
    init_mu(data_arry, &mu);
    
    // split onto k nodes... later

    // find mean
    //calc_mean(data_arry, labels, mu);
    // calculate distance in each row
    int node_idx;
    for(node_idx = 0; node_idx < K; node_idx++)
        calc_distance(data_arry,mu,dist,node_idx);
    
    free_data(&data_arry);
}
