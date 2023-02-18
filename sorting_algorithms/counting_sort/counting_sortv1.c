#include <stdio.h>
#include <string.h>
#define MAX_VALUE 5
#define SIZE 5

void counting_sort(int *array) {
    int B[SIZE - 1] = { 0 };
    int C[MAX_VALUE + 1] = { 0 };

    for (int i = 0; i < SIZE; i++) 
        C[array[i]]++;


    for (int i = 1; i <= MAX_VALUE; i++) 
        C[i] += C[i - 1];

    for (int i = SIZE - 1; i >= 0; i--) {
        B[C[array[i]] - 1] = array[i];
        C[array[i]]--;
    }

    memcpy(array, B, SIZE * sizeof(int));
}

int main(int argc, char** argv) {
    int array[] = { 4, 2, 5, 2, 3 };

    counting_sort(array);
    
    for (int i = 0; i < SIZE; i++) 
        printf("%d ", array[i]);

    printf("\n");

    return 0;
}