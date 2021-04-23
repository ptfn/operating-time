object pi extends App{
    def pi(n: Int): Double = {
        var num = 4.0
        var den = 1.0
        var oper = 1.0
        var pi = 0.0  
        var i = n
        while (i > 0){
            pi += oper * (num / den)
            den += 2.0
            oper *= -1.0
            i -= 1
            }
        return pi
    }
    println("Pi:" + pi(args(0).toInt))
}
