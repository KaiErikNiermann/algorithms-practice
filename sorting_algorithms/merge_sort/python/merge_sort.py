from cmath import inf
from math import floor

A = [5, 2, 4, 6, 1, 3] # unsorted array

def Merge(A, start, mid, end):
    n1 = mid - start + 1
    n2 = end - mid
    L = [] 
    R = [] 
    for i in range(1, n1 + 1):
        L.append(A[start + i - 1])
    for j in range(1, n2 + 1):
        R.append(A[mid + j])
    L.append(inf)
    R.append(inf)
    i = 0
    j = 0
    for k in range(start, end + 1):
        if L[i] <= R[j]:
            A[k] = L[i] # left wins
            i += 1
        else:
            A[k] = R[j] # right wins
            j += 1

def MergeSort(A, start, end):
    if start < end:
        mid = floor((start + end)/2)
        MergeSort(A, start, mid)
        MergeSort(A, mid + 1, end)
        Merge(A, start, mid, end)


MergeSort(A, 0, len(A) - 1)

print(list(A))
