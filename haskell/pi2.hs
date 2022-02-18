func :: Double -> Double
func n = 1 / n ^ 2

numpi :: Double -> Double
numpi n = sqrt(sum(map (func) [1..n])*6)

main :: IO()
main = print(numpi 1000000)
