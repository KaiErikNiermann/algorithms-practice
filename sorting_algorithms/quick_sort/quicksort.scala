object quicksort extends App {
    def swap(arr: Array[Int], i: Int, j: Int) : Unit = {
        val temp = arr(i)
        arr(i) = arr(j)
        arr(j) = temp
    }
    
    def partition(arr: Array[Int], start: Int, end: Int) : Int = {
        val pivot = arr(end)
        var i = start - 1
        (start until end).foreach(j => {
            if (arr(j) <= pivot) {
                i += 1
                swap(arr, i, j)
            } })
            
        swap(arr, i + 1, end)
        i + 1
    }
    
    def quicksort(arr: Array[Int], start: Int, end: Int) : Unit = {
        if (start < end) {
            val pivot = partition(arr, start, end)
            quicksort(arr, start, pivot - 1)
            quicksort(arr, pivot + 1, end)
        }
    }

    val arr = Array(5, 4, 3, 2, 1)
    quicksort(arr, 0, arr.length - 1)
    println(arr.mkString(" "))
}