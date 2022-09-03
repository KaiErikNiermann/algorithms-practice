#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, end;
double cpu_time_used;

void Merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = calloc(1, sizeof(int));
    int *R = calloc(1, sizeof(int));
    L = realloc(L, sizeof(int) * (n1 + 1));
    R = realloc(R, sizeof(int) * (n2 + 1));
    for (int i = 1; i < n1 + 1; i++) {
        L[i-1] = A[p + i - 1];
    }
    for (int j = 1; j < n2 + 1; j++) {
        R[j-1] = A[q + j];   
    }
    double sentinel = 2147483647;
    L[n1] = sentinel;
    R[n2] = sentinel;
    int i = 0;
    int j = 0;
    for (int k = p; k < r + 1; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i += 1;
        } else {
            A[k] = R[j];
            j += 1;
        }
    }
    free(L);
    free(R);
}

void MergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = ((p + r)/2);
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    } 
}

int main() {
    int A[7] = {5, 2, 4, 6, 1, 3, 7};

    MergeSort(A, 0, 6);

    return 0;
}