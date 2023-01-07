def bucket_sort(A):
    # creates len(A) empty buckets
    B = [[] for _ in range(len(A))]

    # distribute the numbers into the buckets
    for i in range(len(A)):
        B[int(len(A) * A[i])].append(A[i])

    # sort each bucket
    for i in range(len(A)):
        insertion_sort(B[i])

    # concatenate the buckets
    return [a for b in B for a in b]

def insertion_sort(A):
    for i in range(1, len(A)):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = key

A = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434]
print(bucket_sort(A))

