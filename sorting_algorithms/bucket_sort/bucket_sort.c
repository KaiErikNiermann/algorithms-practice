#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define BUCKET_SIZE 10

typedef struct {
    int size;
    double values[BUCKET_SIZE];
} Bucket;

double *insertion_sort(double *arr, int n) {
    for(int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

double *bucket_sort(double *arr, int n) {
    Bucket B[n];

    for(int i = 0; i < n; i++) 
        B[i].size = 0;
    
    for(int i = 0; i < n; i ++) {
        int *bucket_size = &(B[(int)(n * arr[i])].size); // used to append values to the bucket
        int bucket_index = (int)floor(n * arr[i]);
        B[bucket_index].values[(*bucket_size)++] = arr[i];
    }

    // sort each bucket using insertion sort and copy the sorted bucket back into the original
    for(int i = 0; i < n; i++) 
        memcpy(insertion_sort(B[i].values, B[i].size), B[i].values, B[i].size * sizeof(int));

    // concatenate all the buckets into the original array
    for(int i = 0, j = 0; i < n; i++) 
        for(int k = 0; k < B[i].size; k++) 
            arr[j++] = B[i].values[k];
    
    return arr;
}


int main() {
    double A[BUCKET_SIZE] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68}; 
    memcpy(A, bucket_sort(A, BUCKET_SIZE), BUCKET_SIZE * sizeof(int));
    
    for(int i = 0; i < BUCKET_SIZE; i++) 
        printf("%f ", A[i]);
    
    return 0;
}