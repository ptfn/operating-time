isPrime :: Int -> Bool
isPrime k = length [ x | x <- [2..k], k `mod` x == 0] == 1

findPrime :: Int -> Int
findPrime n = if isPrime(n) == True then n else findPrime(n+1)

prod :: (Integral a) => a -> a -> a
prod p q = p * q

elier :: (Integral a) => a -> a -> a
elier p q = (p - 1) * (q - 1)

dres :: (Integral a) => a -> a -> a -> a
dres e el n
    | (mod (e*n) el) == 1 = n 
    | el <= n = 0
    | otherwise = dres e el (n+1)

enc :: (Integral a) => a -> a -> a -> a
enc m e n = mod(m^e) n

dec :: (Integral a) => a -> a -> a -> a
dec c d n = mod(c^d) n


p = findPrime 100^501
q = findPrime 100^488
n = prod p q
el = elier p q
e = findPrime 2^16
d = dres e el 0

main :: IO()
main = do
    print(p)
    print(q)
    print(e)

