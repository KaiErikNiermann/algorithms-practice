import time

def BottomUpMerge(A, start, mid, end, B):
    i = start 
    j = mid

    for k in range(start, end):
        if (i < mid and (j >= end or A[i] <= A[j])):
            B[k] = A[i]
            i += 1
        else:
            B[k] = A[j]
            j += 1

def BottomUpMergeSort(A, B, n):
    width = 1
    while(width < n):
        for i in range(0, n, 2 * width):
            BottomUpMerge(A, i, min(i + width, n), min(i + 2 * width, n), B)

        A = [k for k in B]
        width *= 2

    return A

A = [5, 2, 4, 6, 1, 3]
B = [None] * len(A)

A = BottomUpMergeSort(A, B, len(A))

print(list(A))