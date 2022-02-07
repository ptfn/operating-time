p = 0.0
num = 4.0
den = 1.0
oper = 1.0

pise :: Int -> Double -> Double -> Double -> Double -> Double
pise n p num den oper
    | n == 0 = p
    | otherwise = pise (n-1) (p + oper * (num / den)) num (den + 2) (oper * (-1))

main :: IO()
main = do
    print(pise 1000000 p num den oper)