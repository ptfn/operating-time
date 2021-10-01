fac :: Integer -> Integer
fac 0 = 1
fac n | n > 0 = n * fac (n - 1)

main :: IO()
main = print(fac 1000^1000)
