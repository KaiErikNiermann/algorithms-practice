#include <stdio.h>
#include <stdlib.h>
#define PARENT(i) (i - 1) / 2
#define LEFT(i) 2 * i + 1
#define RIGHT(i) 2 * i + 2

typedef struct {
    int size;
    int *array;
} MaxHeap;

void swap(int H[], int i, int j) {
    int temp = H[i];
    H[i] = H[j];
    H[j] = temp;
}

void maxHeapify(MaxHeap heap, int i) {
    int left = LEFT(i);
    int right = RIGHT(i);
    int largest = i;

    if (left < heap.size && heap.array[left] > heap.array[i]) {
        largest = left;
    }
    if (right < heap.size && heap.array[right] > heap.array[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(heap.array, i, largest);
        maxHeapify(heap, largest);
    }
}

void buildMaxHeap(MaxHeap heap) {
    for (int i = heap.size / 2 - 1; i >= 0; i--) 
        maxHeapify(heap, i);
}

int maxHeapExtractMax(MaxHeap heap) {
    if (heap.size < 1) {
        printf("heap underflow\n");
        return -1;
    }
    int max = heap.array[0];
    heap.array[0] = heap.array[heap.size - 1];
    heap.size--;
    maxHeapify(heap, 0);
    return max;
}


void maxHeapInsert(MaxHeap heap, int key) {
    heap.size++;
    heap.array[heap.size - 1] = -1;
    maxHeapIncreaseKey(heap, heap.size - 1, key);
}

void maxHeapIncreaseKey(MaxHeap heap, int i, int key) {
    if (key < heap.array[i]) {
        printf("new key is smaller than current key\n");
        return;
    }
    heap.array[i] = key;
    while (i > 0 && heap.array[PARENT(i)] < heap.array[i]) {
        swap(heap.array, i, PARENT(i));
        i = PARENT(i);
    }
}

int main(int argc, char** argv) {
    MaxHeap heap;
    heap.size = 7;
    heap.array = (int*)malloc(heap.size * sizeof(int));
    heap.array = (int[]) { 0, 5, 2, 4, 6, 1, 3 };

    for (int i = 0; i < heap.size; ++i) 
        printf("%d ", heap.array[i]);
    printf("\n");

    return 0;
}