object func_merge_sort extends App {
    def mergeSort[T](list: List[T])(implicit ordering: Ordering[T]): List[T] = {
        def merge(left: List[T], right: List[T]): List[T] = (left, right) match {
            case (Nil, _) => right
            case (_, Nil) => left
            case (x :: xs, y :: ys) =>
                if (ordering.lt(x, y)) 
                    x :: merge(xs, right) 
                else 
                    y :: merge(left, ys)
        }

        val mid = list.length / 2
        if (mid == 0) list
        else {
            val (left, right) = list.splitAt(mid)
            merge(mergeSort(left), mergeSort(right))
        }
    }

    var list : List[Int] = List(5, 4, 3, 2, 1)
    println(mergeSort(list)(implicitly[Ordering[Int]]))
}