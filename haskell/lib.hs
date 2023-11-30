first :: (a, b, c, d) -> (a, d)
first (a, _, _, d) = (a, d)

head' :: [a] -> a
head' [] = error "Array Null"
head' (x:_) = x

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
    let small = quicksort [a | a <- xs, a <= x]
        big = quicksort [a | a <- xs, a > x]
    in small ++ [x] ++ big

findlist :: (Eq a) => a -> [a] -> [a]
findlist a [] = []
findlist a (x:xs)
    | a == x = findlist a xs ++ [x]
    | otherwise = findlist a xs
