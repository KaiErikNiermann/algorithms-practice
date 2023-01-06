# this is a more readable variant but works on similar principles 
def readable_counting_sort(A, k):
    n = len(A)
    m = k + 1
    count = [0] * m  
    for a in A:
        count[a] += 1

    i = 0
    for a in range(m):  
        for c in range(count[a]): 
            A[i] = a
            i += 1

    return A


# this is the one generally used in textbooks
def counting_sort(A, k):
    C = [0] * k
    B = [0] * len(A)
    for j in range(len(A)):
        C[A[j]] = C[A[j]] + 1 # C[i] now contains the number of elements equal to i.

    for i in range(1, k):
        C[i] = C[i] + C[i - 1] # C[i] now contains the number of elements less than or equal to i.

    for j in range(len(A) - 1, -1, -1):
        B[C[A[j]] - 1] = A[j]  # C[A[j]] contains the index and since 0th indexing we do -1
        C[A[j]] = C[A[j]] - 1 # handling duplicates
    return B

a = [0, 5, 2, 4, 5, 1, 3]
print(counting_sort(a, 7))
print(readable_counting_sort(a, 7))

