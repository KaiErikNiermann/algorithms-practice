#include <stdio.h>
#include <stdlib.h>

void swap(int H[], int i, int j) {
    int temp = H[i];
    H[i] = H[j];
    H[j] = temp;
}

// maintains the max heap property
void maxHeapify(int H[], int heapSize, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < heapSize && H[left] > H[i]) {
        largest = left;
    }
    if (right < heapSize && H[right] > H[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(H, i, largest);
        maxHeapify(H, heapSize, largest);
    }
}

// builds the max heap
void buildMaxHeap(int H[], int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        maxHeapify(H, heapSize, i);
    }
}

// builds the max heap then sorts the array
void heapsort(int H[], int heapSize) {
buildMaxHeap(H, heapSize);
    for (int i = heapSize - 1; i >= 0; i--) {
        swap(H, 0, i);
        maxHeapify(H, i, 0);
    }
}

int main() {
    int H[] = {0, 5, 3, 17, 10, 84, 19, 6, 22, 9};
    int heapSize = sizeof(H) / sizeof(H[0]);
	
    heapsort(H, heapSize);

    for (int i = 0; i < heapSize; ++i) 
        printf("%d ", H[i]);
    printf("\n");

    return 0;
}
