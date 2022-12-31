object test extends App {
    def test() : Unit = {
        var list : List[Int] = List(1, 2, 3)
        list match {
            case x :: xs => println(f"x = $x, xs = $xs")
            case Nil => println("Nil")
        }
    }
    test()
}