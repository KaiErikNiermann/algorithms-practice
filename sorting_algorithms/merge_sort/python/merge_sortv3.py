from math import floor

def TopDownMerge(A, start, mid, end, B):
    i = start 
    j = mid

    for k in range(start, end):
        if (i < mid and (j >= end or A[i] <= A[j])):
            B[k] = A[i]
            i += 1
        else:
            B[k] = A[j]
            j += 1

def TopDownSplitMerge(B, start, end, A):
    if (end - start <= 1):
        return

    mid = floor((start + end) / 2)
    TopDownSplitMerge(A, start, mid, B)
    TopDownSplitMerge(A, mid, end, B)
    TopDownMerge(B, start, mid, end, A)

A = [5, 2, 4, 6, 1, 3]
B = A.copy()

TopDownSplitMerge(B, 0, 6, A)

print(list(A))


