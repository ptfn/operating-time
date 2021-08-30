(defn fc
    [n]
    (if (= n 1)
        1
        (* n (fc(- n 1)))))
(println (fc 10))