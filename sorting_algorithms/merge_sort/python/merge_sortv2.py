from cmath import inf
from math import floor

A = [2, 4, 3, 1] # unsorted array


def Merge(A, start, mid, end):
    n1 = mid - start + 1 # +1 because 0 index 
    n2 = end - mid
    cpy = n1 + n2

    B = [] 
    
    for j in range(1, cpy + 1):
        if (j == (n1 + 1)): B.append(inf)
        B.append(A[start + j - 1])
    B.append(inf)

    i = 0
    j = n1 + 1 # +1 to skip inf 
    for k in range(start, end + 1):
        if B[i] <= B[j]:
            A[k] = B[i] # left wins
            i += 1
        else:
            A[k] = B[j] # right wins
            j += 1

def MergeSort(A, start, end):
    if (start >= end):
        return

    mid = floor((start + end) / 2)
    MergeSort(A, start, mid)
    MergeSort(A, mid + 1, end)
    Merge(A, start, mid, end)


MergeSort(A, 0, len(A) - 1)

