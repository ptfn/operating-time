(define (fac n)
    (if (= n 1)
        1
        (* n (fac(- n 1)))))
(display (fac 10000))
(newline)
        