object fibonachi extends App {
    def fib(n: Int): Int = {
        if(n>1) fib(n-1) + fib(n-2)
        else 1
    }
    println(fib(20))
}
