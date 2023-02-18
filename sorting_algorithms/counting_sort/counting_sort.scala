object counting_sort extends App {
    def c_sort(arr: Array[Int]) : Unit = {
        val count = Array.fill(arr.max + 1)(0)
        for (i <- arr) count(i) += 1

        var k = 0  // index of arr
        for (i <- 0 to arr.max) {
            for (j <- 0 until count(i)) {
                arr(k) = i
                k += 1
            }
        }
    }

    def test() : Unit = {
        val arr = Array(1, 4, 1, 2, 7, 5, 2)
        c_sort(arr)
        println(arr.mkString(" "))
    }
    test()
}