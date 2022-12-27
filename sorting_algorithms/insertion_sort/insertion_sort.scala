object insertion_sort extends App {
    def insertionSort(arr: Array[Int]) : Unit = {
        (1 until arr.length).foreach(i => {
            val key = arr(i)
            var j = i - 1
            while (j >= 0 && arr(j) > key) {
                arr(j+1) = arr(j) // shift element to right 
                j -= 1
            }
            arr(j+1) = key // insert key into correct position
        })
    }
    var arr = Array(0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7)
    insertionSort(arr)
    println(arr.mkString(" "))
}