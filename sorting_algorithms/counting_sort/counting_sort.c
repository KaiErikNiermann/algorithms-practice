#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 5

void counting_sort(int *array, int size) {
    int count[MAX_VALUE + 1] = { 0 };

    // Count the number of occurrences of each element
    for (int i = 0; i < size; i++) 
        count[array[i]]++;

    // Sort the array
    int k = 0;
    for (int i = 0; i <= MAX_VALUE; i++) {
        for (int j = 0; j < count[i]; j++) {
            array[k] = i;
            k += 1;
        }
    }
}

int main(int argc, char **argv) {
    int array[] = { 4, 2, 5, 1, 3 };
    int size = sizeof(array) / sizeof(int);

    // Sort the array
    counting_sort(array, size);

    // Print the sorted array
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
