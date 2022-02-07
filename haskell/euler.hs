fac :: Double -> Double
fac n = product[1..n]

form :: Double -> Double
form n = 1 / fac n

euler :: Double -> Double
euler n = sum[form x | x <- [0..n]]

main :: IO()
main = print(euler 10000)