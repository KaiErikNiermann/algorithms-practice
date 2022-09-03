#include <stdio.h>
#include <stdlib.h>

int *insertion_sort(int A[], int arry_length) {
    int i = 1;
    int j = 0;
    while (i < arry_length) {
        int key = A[i];
        j = i - 1;
        while( j >= 0 && A[j] < key) {
            A[j + 1] = A[j];
            j -= 1;
        }

        A[j + 1] = key;
        i += 1;
    }

    return A;
}

int main() {
    int myarray[] = {5, 2, 4, 6, 1, 3};
    int *sorted_array = insertion_sort(myarray, 6);

    for (size_t i = 0; i < 6; i++) {
        printf("%d\n", sorted_array[i]);
    }
    
    return 0;
}