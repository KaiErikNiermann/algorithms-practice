object priority_queue extends App {
    def swap(arr: Array[Int], i: Int, j: Int) : Unit = {
        val temp = arr(i)
        arr(i) = arr(j)
        arr(j) = temp
    }
    
    def maxHeapify(arr: Array[Int], heapSize: Int, i: Int) : Unit = {
        val left = 2 * i + 1
        val right = 2 * i + 2
        var largest = i
        if (left < heapSize && arr(left) > arr(i)) 
            largest = left
        
        if (right < heapSize && arr(right) > arr(largest)) 
            largest = right

        if (largest != i) {
            swap(arr, i, largest)
            maxHeapify(arr, heapSize, largest)
        }
    }
    
    def buildMaxHeap(arr: Array[Int], heapSize: Int): Unit = {
        ((heapSize / 2)-1 to 0 by -1).foreach(i => 
            maxHeapify(arr, heapSize, i)
        )
    }
    
    def extractMax(arr: Array[Int], heapSize: Int) : (Int, Array[Int]) = {
        val max = arr(0)
        arr(0) = arr(heapSize-1)
        var updatedArr = arr
        updatedArr = arr.dropRight(1)
        maxHeapify(updatedArr, heapSize-1, 0)
        (max, updatedArr)
    }

    def testPQ() : Unit = {
        var arr : Array[Int]  = Array(0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7)
        var max : Int = 0
        buildMaxHeap(arr, arr.length)
        var (a, b) = extractMax(arr, arr.length)
        print(f"max = $a, arr = ${b.mkString(" ")}")
    }
    testPQ()
}