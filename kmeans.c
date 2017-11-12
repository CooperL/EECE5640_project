#include <stdio.h>
#include "data.h"

#define N 10000
#define D 10
#define DATA_FILE "samples.csv"
#define LABEL_FILE "clusters.csv"

int main(int argc, char* argv[]) {
    int i,j;
    float** data_arry;
    init_data(&data_arry,N,D);

    FILE* data_fp = fopen(DATA_FILE,"r");
    FILE* label_fp = fopen(LABEL_FILE,"r");

    read_csv(data_fp,label_fp,data_arry,N,D);
    //print_data(data_arry,N,D);

    free_data(&data_arry,N,D);
}
