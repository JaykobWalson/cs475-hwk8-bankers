#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"

// TODO - Define vector and matrix operations

//

//Sanity checks and gets the matrix.
int getNeedMatrix() {
    for (int i=0; i<num_threads; i++) {
        for (int j=0; j<num_resources; j++) {
            if (allocation[i][j] <= max[i][j]) {
                need[i][j] = max[i][j] - allocation[i][j];//sanity check
            } 
			else {
                int difference = max[i][j] - allocation[i][j];
                printf("Integrity test failed: allocated resources exceed demand for Thread %d\n", i);
                printf("Need %d instances of resource %d\n", difference, j);
                return 0;
            }
        }
    }
    return 1;
}

//Compares a row to another to check if the number of work they do is the same
//@param *rowOfNeed is the row to bee compared to
//@param *work is the number of work done by the row
//@param num_resources is the total number of resources in the matrix's row
int compareRow(int *rowOfNeed, int *work, int num_resources) {
    for (int j = 0; j < num_resources; j++) {
        if (rowOfNeed[j] > work[j]) {
            return 0;
        }
    }
    return 1;
}

