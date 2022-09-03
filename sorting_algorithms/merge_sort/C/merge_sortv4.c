#include <stdio.h>
#include <math.h>

void BottomUpMerge(int A[], int start, int mid, int end, int B[]) {
    int i = start;
    int j = mid;

    for (int k = start; k < end; k++) {
        if (i < mid && (j >= end || A[i] <= A[j])) 
            B[k] = A[i++];
        else
            B[k] = A[j++];
    }
}

void BottomUpMergeSort(int A[], int B[], int n) {
    for (int width = 1; width < n; width = 2 * width) {
        for (int i = 0; i < n; i = i + 2 * width) {
            BottomUpMerge(A, i, fmin(i + width, n), fmin(i + 2 * width, n), B);
        }

        for (int k = 0; k < n; k++)
            A[k] = B[k];
    }
}

int main() {
    int A[6] = {5, 2, 4, 6, 1, 3};
    int B[6];

    BottomUpMergeSort(A, B, 6);

    for (int i = 0; i < 6; i++)
        printf("%d, ", A[i]);
    printf("\n");

    return 0;
}