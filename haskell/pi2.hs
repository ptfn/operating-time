func :: Double -> Double
func n = 1 / n

numpi :: Double -> Double
numpi n = sqrt(sum(map (func) [x^2 | x <- [1..n]])*6)

main :: IO()
main = print(numpi 1000000)
