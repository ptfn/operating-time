fibs = 0:1:zipWith (+) fibs (tail fibs)
main = print(fibs !! 10000)
