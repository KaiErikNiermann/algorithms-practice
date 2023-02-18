def heapsort(a, heapSize):
    buildMaxHeap(a, heapSize)
    for i in range(heapSize-1, -1, -1):
        a[0], a[i] = a[i], a[0]
        maxHeapify(a, i, 0)

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

a = [0, 5, 2, 4, 6, 1, 3]
heapsort(a, len(a))
print(a)
