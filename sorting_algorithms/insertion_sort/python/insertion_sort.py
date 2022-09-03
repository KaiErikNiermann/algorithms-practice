A = [5, 2, 4, 6, 1, 3] # unsorted array

def insertion_sort(A):
    i = 1
    while i < len(A):
        j = i
        while j > 0 and A[j - 1] > A[j]: # ( A[j - 1] < A[j] ) for decreasing
            A[j], A[j - 1] = A[j - 1], A[j]
            j -= 1

        i += 1
    return A


def insertion_sort_fast(A):
    i = 1
    while i < len(A):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] < key: # ( A[j] > key ) for increasing
            A[j + 1] = A[j]
            j -= 1

        A[j + 1] = key
        i += 1
    return A

# sorted_array = insertion_sort(A)
sorted_array = insertion_sort_fast(A)

for i in sorted_array:
    print(i)



def insertion_sort(A):
    i = 1
    while (i < len(A)):
        key = A[i]
        j = i - 1
        while ( j >= 0 and A[j] < key):
            A[j + 1] = A[j] # swap operation 
            j -= 1

        A[j + 1] = key
        i += 1