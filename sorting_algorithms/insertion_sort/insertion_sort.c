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

int *insertion_sort2(int A[], int array_length) {
    for (size_t j = 1; j < array_length; j++) {
        int key = A[j];
        int i = j - 1;
        while(i >= 0 && A[i] < key) {
            A[i + 1] = A[i];
            i -= 1;
        }
        A[i + 1] = key;
    }
    return A;
}


int *insertion_sort3(int A[], int array_length) {
    for (size_t j = 1; j < array_length; j++) {
        int key = A[j];
        int i = j - 1;
        while(i >= 0 && A[i] < key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
    return A;    
}


// best case O(n)
// worst case O(n^2)
// average case O(n^2)
int main() {
    int myarray[] = {5, 2, 4, 6, 1, 3};
    int *sorted_array = insertion_sort3(myarray, 6);

    for (size_t i = 0; i < 6; i++) {
        printf("%d\n", sorted_array[i]);
    }
    
    return 0;
}