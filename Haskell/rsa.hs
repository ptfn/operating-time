isPrime :: Int -> Bool
isPrime k = length [ x | x <- [2..k], k `mod` x == 0] == 1

findPrime :: Int -> Int
findPrime n = if isPrime(n) == True then n else findPrime(n+1)

prod :: (Integral a) => a -> a -> a
prod p q = p * q

elier :: (Integral a) => a -> a -> a
elier p q = (p - 1) * (q - 1)

-- dres :: Int -> Int -> Int -> Bool
-- dres e el n = if (mod (e * n) el) == 1 then n  

p = 3557 --findPrime 100^10
q = 2579 --findPrime 100^11
e = 3 --indPrime 100^1
n = prod p q
el = elier p q


main :: IO()
main = print(el)