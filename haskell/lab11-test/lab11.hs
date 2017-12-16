data (Dom a) = Empty
           | Full
           | Ran a a
           | (Dom a) :|: (Dom a)
           | (Dom a) :&: (Dom a)
           deriving (Show, Read)


instance Eq a => Eq (Dom a) where
    Empty == Empty = True
    Full == Full = True
    (Ran x y) == (Ran n m) = (x == n) && (y == m)
    _ == _ = False


exist :: Ord a => a -> (Dom a) -> Bool
exist x Empty = False
exist x Full = True 
exist x (Ran p q) = (x >= p) && (x <= q)
exist x (p :|: q) = (exist x p) || (exist x q)
exist x (p :&: q) = (exist x p) && (exist x q)

overlap :: Ord a => (Dom a) -> (Dom a) -> Bool
overlap Empty _ = False 
overlap _ Empty = False
overlap Full _ = True
overlap _ Full = True
overlap (Ran a b) (Ran c d) =
     (a <= c && c <= b) ||  -- a < c < b
     (a <= d && d <= b) ||  -- a < d < b
     (c <= a && a <= d) ||  -- c < a < d
     (c <= b && b <= d)     -- c < b < d

normalize :: Ord a => Dom a -> Dom a
normalize Empty = Empty
normalize r@(Ran _ _) = r
normalize ((x :|: y) :&: z) = normalize (x :&: z) :|: normalize (y :&: z)
normalize (x :|: y) = normalize x :|: normalize y
normalize (x :&: y) = normalize x :&: normalize y


optimize :: Ord a => Dom a -> Dom a
optimize Empty = Empty
optimize r@(Ran _ _) = r

optimize (x :|: Empty) = optimize x  -- U
optimize (Empty :|: x) = optimize x  -- U
optimize (_ :&: Empty) = Empty
optimize (Empty :&: _) = Empty

optimize r@(Ran a b :|: Ran c d)  -- U
  | overlap (Ran a b) (Ran c d) = Ran (min a c) (max b d)
  | otherwise = r
optimize (Ran a b :&: Ran c d)
  | overlap (Ran a b) (Ran c d) = Ran (max a c) (min b d)
  | otherwise = Empty

optimize (x :|: y) = optimize $ optimize x :|: optimize y
optimize (x :&: y) = optimize $ optimize x :&: optimize y


main :: IO (Dom Int)
main = do
  line <- getLine
  let d = read line :: Dom Int
  return (optimize d)
