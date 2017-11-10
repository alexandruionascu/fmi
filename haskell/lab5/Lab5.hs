-- Informatics 1 - Functional Programming 
-- Declarative Programming 
-- Lab 5

import Data.Char
import Data.List
import Test.QuickCheck



-- 1. Map
-- a. (4 simboluri)
uppers :: String -> String
uppers = map toUpper 

-- b. (7 simboluri)
doubles :: [Int] -> [Int]
doubles = map (*2)

-- c. (10 simboluri)
penceToPounds :: [Int] -> [Float]
penceToPounds = map (\x -> fromIntegral x / 100)

-- d. (11 simboluri)
uppers' :: String -> String
uppers' xs = [toUpper x | x <- xs]

-- (8 simboluri)
prop_uppers :: String -> Bool
prop_uppers xs = uppers xs == uppers' xs



-- 2. Filter
-- a. (4 simboluri)
alphas :: String -> String
alphas xs = filter (\x -> toUpper x `elem` ['A'..'Z']) xs

-- b. (8 simboluri)
rmChar ::  Char -> String -> String
rmChar c xs = filter (/= c) xs

-- c. (8 simboluri)
above :: Int -> [Int] -> [Int]
above n xs = filter (>n) xs

-- d. (13 simboluri)
unequals :: [(Int,Int)] -> [(Int,Int)]
unequals = filter (\(x, y) -> x /= y)

-- e. (15 simboluri)
rmCharComp :: Char -> String -> String
rmCharComp c xs = [x | x <- xs, x /= c]

-- (11 simboluri)
prop_rmChar :: Char -> String -> Bool
prop_rmChar c xs = rmChar c xs == rmCharComp c xs



-- 3. Comprehensions vs. map & filter
-- a. 
upperChars :: String -> String
upperChars s = [toUpper c | c <- s, isAlpha c]

-- (7 simboluri)
upperChars' :: String -> String
upperChars' xs = map (toUpper) $ filter (\x -> isAlpha x) xs

prop_upperChars :: String -> Bool
prop_upperChars s = upperChars s == upperChars' s

-- b. 
largeDoubles :: [Int] -> [Int]
largeDoubles xs = [2 * x | x <- xs, x > 3]

-- (13 simboluri)
largeDoubles' :: [Int] -> [Int]
largeDoubles' xs = map (*2) $ filter (>3) xs

prop_largeDoubles :: [Int] -> Bool
prop_largeDoubles xs = largeDoubles xs == largeDoubles' xs 

-- c.
reverseEven :: [String] -> [String]
reverseEven strs = [reverse s | s <- strs, even (length s)]

-- (11 simboluri)
reverseEven' :: [String] -> [String]
reverseEven' xs = map (reverse) $ filter (even . length) xs

prop_reverseEven :: [String] -> Bool
prop_reverseEven strs = reverseEven strs == reverseEven' strs



-- 4. Foldr
-- a.
productRec :: [Int] -> Int
productRec []     = 1
productRec (x:xs) = x * productRec xs

-- (7 simboluri)
productFold :: [Int] -> Int
productFold = undefined

prop_product :: [Int] -> Bool
prop_product xs = productRec xs == productFold xs

-- b.  (16 simboluri)
andRec :: [Bool] -> Bool
andRec [] = True
andRec (x:xs) = if x then andRec xs else False

-- (7 simboluri)
andFold :: [Bool] -> Bool
andFold xs = foldl (&&) True xs

prop_and :: [Bool] -> Bool
prop_and xs = andRec xs == andFold xs 

-- c.  (17 simboluri)
concatRec :: [[a]] -> [a]
concatRec [] = []
concatRec (x:xs) = x ++ (concatRec xs)

-- (8 simboluri)
concatFold :: [[a]] -> [a]
concatFold xs = foldr (++) [] xs

prop_concat :: [String] -> Bool
prop_concat strs = concatRec strs == concatFold strs

-- d.  (17 simboluri)
rmCharsRec :: String -> String -> String
rmCharsRec _ [] = []
rmCharsRec chars (x:xs) = if x `elem` chars then rmCharsRec chars xs else x : rmCharsRec chars xs

-- (6 simboluri)
rmCharsFold :: String -> String -> String
rmCharsFold chars xs = foldr (\x acc -> if x `elem` chars then acc else x : acc) [] xs

prop_rmChars :: String -> String -> Bool
prop_rmChars chars str = rmCharsRec chars str == rmCharsFold chars str



type Matrix = [[Int]]


-- 5
-- a. (10 simboluri)
uniform :: [Int] -> Bool
uniform [] = True
uniform [x] = True
uniform (x:xs) = all (==x) xs

-- b. (	 simboluri)
valid :: Matrix -> Bool
valid xs = let lens = map (length) xs in (uniform lens && all (>0) lens)

-- 6.

-- 7.  (22 simboluri + 19 simboluri)  cu tot cu tratarea erorilor
plusM :: Matrix -> Matrix -> Matrix
plusM a b 
    | valid a && valid b = [uncurry (zipWith (+)) (xs, ys) | (xs, ys) <- zip a b]
    | otherwise = error "Invalid matricies." 

-- 8. (23 simboluri + 15 simboluri)  cu tot cu tratarea erorilor  
timesM :: Matrix -> Matrix -> Matrix
timesM xs ys = [dot row column | row <- xs, column <- transpose ys]
dot :: [Int] -> [Int] -> Int
dot xs ys = sum $ zipWith (*) xs ys

