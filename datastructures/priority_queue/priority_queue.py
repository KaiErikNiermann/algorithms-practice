from math import inf

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

def extractMax(a, heapSize):
    max_val = a[0]                
    a[0] = a[heapSize - 1]         
    a.pop()     
    maxHeapify(a, heapSize - 1, 0) 
    return max_val

def insert(a, key, heapSize):
    k = key
    key = -inf      # -inf to avoid error in increaseKey
    a.append(key)
    increaseKey(a, len(a) - 1, k)

def increaseKey(a, i, key):
    if key < a[i]: # only required for modifying existing key
        print("error: New key is smaller than current key")
        return
    a[i] = key
    while i != 0 and a[i // 2] < a[i]:
        a[i], a[i // 2] = a[i // 2], a[i]
        i = i // 2

def deleteKey(a, key, heapSize):
    for i in range(0, len(a)-1):
        if a[i] == key:
            a[i], a[heapSize - 1] = a[heapSize - 1], a[i]
            a.pop()
            buildMaxHeap(a, len(a)-1)


a = [20, 10, 15, 7, 5, 8, 9]
buildMaxHeap(a, len(a))
print(a)
deleteKey(a, 15, len(a))
print(a)
