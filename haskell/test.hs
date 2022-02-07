double :: (Num a) => a -> a
double x = x * 2

list :: (Num a, Enum a) => a -> [a]
list n = [1..n]

sum' :: (Num a) => a -> a -> a
sum' a b = a + b

len' :: String -> Int
len' n = length n

main = print(list 100)