object bucket_sort extends App {
    def bucket_sort(A: Array[Double]) : Array[Double] = {
        // Create an array of arrays of Doubles
        val B : Array[Array[Double]] = Array.ofDim[Double](A.length, 0)
        
        // Insert each element of A into the appropriate bucket
        for (i <- 0 until A.length) 
            B((A.length * A(i)).toInt) :+= A(i)

        // Sort each bucket
        for (i <- 0 until A.length) 
            B(i) = insertion_sort(B(i))
        
        // Flatten the array of arrays into a single array
        return B.flatten
    }

    def insertion_sort(A: Array[Double]) : Array[Double] = {
        (1 until A.length).foreach(i => {
            val key : Double = A(i)
            var j : Int = i - 1
            while (j >= 0 && A(j) > key) {
                A(j + 1) = A(j) 
                j -= 1
            }
            A(j + 1) = key 
        })
        A
    }

    def test : Unit = {
        val A : Array[Double] = Array(0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68)
        val B = bucket_sort(A)
        println(B.mkString(" "))
    }
    test
}