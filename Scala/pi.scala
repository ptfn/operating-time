object pi extends App{
    def pi(n: Int): Double = {
        var num: Double = 4.0
        var den: Double = 1.0
        var oper: Double = 1.0
        var pi: Double = 0.0  
        var i = n
        while (i > 0){
            pi = pi + oper * (num / den)
            den = den + 2.0
            oper = oper * -1.0
            i = i - 1
            }
        return pi
    }
    println("Pi:" + pi(999999))
}