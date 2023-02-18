#include <stdio.h>
#include <stdlib.h>

static int *vector = NULL;
static int vectorSize = 0;
static int capacity = 0;
static const float GrowthFactor = 2;

int push_back(int item) {
    if(vectorSize == capacity) {
        int newSize = capacity == 0 ? 1 : (int)capacity * GrowthFactor;
        int *newArray = (int*)realloc(vector, newSize * sizeof(int));
        if(newArray == NULL) return -1;
        capacity = newSize;
        vector = newArray;
    }
    vector[vectorSize] = item;
    return vectorSize++;
}

int main(int argc, char** argv) {
    int i;
    for(i = 0; i < 100; i++) {
        push_back(i);
    }
    for(i = 0; i < vectorSize; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    return 0;
}