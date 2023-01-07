object Stack extends App {
    case class SStack[A](l : List[A]) {
        def push(a : A) : SStack[A] = SStack(a :: l)

        def pop : SStack[A] = l match {
            case Nil => throw new Exception("Empty stack")
            case _ => SStack(l.tail)
        }

        def top : A = l match {
            case Nil => throw new Exception("Empty stack")
            case _ => l.head
        }

        def isEmpty : Boolean = l.isEmpty
    }

    object SStack {
        def apply[A](a: A) : SStack[A] = SStack(List(a))
        def apply[A]() : SStack[A] = SStack(List())
    }

    def test : Unit = {
        val myStack : SStack[Int] = SStack(1)
        println(myStack.top) 
        println(myStack.push(2).top)
        // println(myStack.pop.top) // Throws an exception

    }
    test
}