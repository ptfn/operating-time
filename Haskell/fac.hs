fac :: Integer -> Integer
fac 0 = 1
fac n | n > 0 = n * fac (n - 1)

main = print(fac 9999)