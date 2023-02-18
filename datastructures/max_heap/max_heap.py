class maxHeap: 
    def __init__(self): 
        self.heap = []
        self.heapSize = 0

    parent = lambda self, i: (i-1)//2
    left = lambda self, i: 2*i + 1
    right = lambda self, i: 2*i + 2

    # O(log n)
    def maxHeapify(self, i):
        l = self.left(i)
        r = self.right(i)
        largest = i

        if l < self.heapSize and self.heap[l] > self.heap[i]:
            largest = l
        if r < self.heapSize and self.heap[r] > self.heap[largest]:
            largest = r
            
        if largest != i:
            self.heap[i], self.heap[largest] = self.heap[largest], self.heap[i]
            self.maxHeapify(largest)

    # O(n)
    def buildMaxHeap(self):
        for i in range(int(self.heapSize/2)-1, -1, -1):
            self.maxHeapify(i)

    # O(log n)
    def maxHeapExtractMax(self):
        if self.heapSize < 1:
            raise Exception("heap underflow")
        max = self.heap[0]
        self.heap[0] = self.heap[self.heapSize-1]
        self.heapSize -= 1
        self.maxHeapify(0)
        return max

    # O(1)
    def maxHeapMaximum(self):
        return self.heap[0]
    
    # O(log n)
    def printHeap(self):
        print(self.heap[0:self.heapSize])
    
    def maxHeapInsert(self, key):
        self.heapSize += 1
        self.heap.append(float("-inf"))
        self.increaseKey(self.heapSize-1, key)

    def increaseKey(self, i, key):
        if key < self.heap[i]:
            raise Exception("new key is smaller than current key")
        self.heap[i] = key
        while i > 0 and self.heap[self.parent(i)] < self.heap[i]:
            self.heap[self.parent(i)], self.heap[i] = self.heap[i], self.heap[self.parent(i)]
            i = self.parent(i)

if __name__ == "__main__":
    a = [0, 5, 2, 4, 6, 1, 3]
    heap = maxHeap()
    heap.heap = a
    heap.heapSize = len(a)
    heap.buildMaxHeap()
    heap.printHeap()
    heap.maxHeapInsert(7)
    heap.printHeap()
    heap.increaseKey(0, 8)
    heap.printHeap()