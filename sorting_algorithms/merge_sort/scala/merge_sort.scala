object merge_sort extends App {
    def mergeSort(arr2: Array[Int], start: Int, end: Int, arr: Array[Int]) : Unit = {
        if (end - start > 1) {
            val mid : Int = ((start + end) / 2).toInt
            mergeSort(arr, start, mid, arr2)
            mergeSort(arr, mid, end, arr2)
            merge(arr2, start, mid, end, arr)
        }
    }

    def merge(arr2: Array[Int], start: Int, mid: Int, end: Int, arr: Array[Int]) : Unit = {
        var i : Int = start
        var j : Int = mid

        (start until end).foreach(k => {
            if (i < mid && (j >= end || arr(i) <= arr(j))) {
                arr2(k) = arr(i)
                i += 1
            } else {
                arr2(k) = arr(j)
                j += 1
            }
        })
    }

    var arr : Array[Int] = Array(0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7)
    var arr2 : Array[Int] = arr.clone()
    mergeSort(arr2, 0, arr.length, arr)
    println(arr2.mkString(" "))
}