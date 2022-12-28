#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int start, int end) {
    int pivot = A[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[end]);
    return i + 1;
}

void quicksort(int A[], int start, int end) {
    if (start < end) {
        int pivot = partition(A, start, end);
        quicksort(A, start, pivot - 1);
        quicksort(A, pivot + 1, end);
    }
}

int main() {
    int A[] = {5, 4, 3, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);
    quicksort(A, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}