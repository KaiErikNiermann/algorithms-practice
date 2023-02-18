def partition(A, start, end):
    pivot = A[end]
    i = start - 1
    array = A[start:end + 1]
    for j in range(start, end):
        if A[j] <= pivot:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[end] = A[end], A[i + 1]
    return i + 1

def quicksort(A, start, end):
    if start < end:
        p = partition(A, start, end)

        quicksort(A, start, p - 1)
        quicksort(A, p + 1, end)

A = [5, 2, 4, 6, 1, 3]
quicksort(A, 0, len(A) - 1)
print(list(A))