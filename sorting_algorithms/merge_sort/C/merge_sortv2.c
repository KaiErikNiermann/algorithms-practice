#include <stdio.h>

void TopDownMerge(int A[], int start, int mid, int end, int B[]) {
    int i = start;
    int j = mid;

    for (int k = start; k < end; k++) {
        if (i < mid && (j >= end || A[i] <= A[j])) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
    }
}

void TopDownSplitMerge(int B[], int start, int end, int A[]) {
    if (end - start <= 1)                     
        return;

    int mid = (start + end) / 2;               
    TopDownSplitMerge(A, start, mid, B);   
    TopDownSplitMerge(A, mid, end, B);   
    TopDownMerge(B, start, mid, end, A);
}

void CopyArray(int A[], int start, int end, int B[]) {
    for (int k = start; k < end; k++)
        B[k] = A[k];
}

void TopDownMergeSort(int A[], int B[], int n) {
    CopyArray(A, 0, n, B);     
    TopDownSplitMerge(B, 0, n, A);    
}

int main() {
    int A[6] = {5, 2, 4, 6, 1, 3};
    int B[6];

    TopDownMergeSort(A, B, 6);

    for (int i = 0; i < 6; i++)
        printf("%d, ", A[i]);
    printf("\n");

    return 0;
}