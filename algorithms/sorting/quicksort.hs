quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = 
	let 
		smallerOrEqual = quicksort [a | a <- xs, a <= x]
		larger = quicksort [a | a <- xs, a > x]
	in smallerOrEqual ++ [x] ++ larger
