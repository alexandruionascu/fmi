data Dom a = Empty
           | Full
           | Ran a a
           | (Dom a) :|: (Dom a)
           | (Dom a) :&: (Dom a)
           deriving (Show)

instance Eq (Dom Eq) where
    Empty == Empty = True
    Full == Full = True
    (==) (Ran x) (Ran x) = True
    _ == _ = False