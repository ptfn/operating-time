(define x 1000)
(define e (expt (+ 1 (exact->inexact (/ 1 x)) ) x))
(display e)
(newline)
