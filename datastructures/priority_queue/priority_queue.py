def maxHeapify(a, heapSize, i):
    l = 2 * i + 1
    r = 2 * i + 2
    largest = i
    if l < heapSize and a[l] > a[i]:
        largest = l
    if r < heapSize and a[r] > a[largest]:
        largest = r
    if largest != i:
        a[i], a[largest] = a[largest], a[i]
        maxHeapify(a, heapSize, largest)

def buildMaxHeap(a, heapSize):
    for i in range(int(heapSize/2)-1, -1, -1):
        maxHeapify(a, heapSize, i)

# extract the max value from the heap and then "bubble down"
def extractMax(a, heapSize):
    max_val = a[0]
    heapSize -= 1
    a[0] = a[heapSize]
    maxHeapify(a, heapSize, 0)
    return max_val

# insert key by appending to the end of the array and then "bubble up"
def insert(a, key, heapSize):
    heapSize += 1
    i = heapSize - 1
    a.append(key)
    while i > 0 and a[int((i-1)/2)] < a[i]:
        parent = int((i-1)/2)
        a[i], a[parent] = a[parent], a[i]
        i = parent

a = [0, 5, 2, 4, 6, 1, 3]
heapSize = len(a)
buildMaxHeap(a, heapSize)
print(a)
for i in range(0, heapSize):
    print(extractMax(a, heapSize), end=' ')
    heapSize -= 1
print()
print(a)
