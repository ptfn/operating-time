object factorial extends App {
    def factorial(n: BigInt): BigInt = {
        if(n>1) n * factorial(n-1) else 1
    }
    println(factorial(30))
}