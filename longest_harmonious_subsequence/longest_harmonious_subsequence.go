package longest_harmonious_subsequence

// 594. Longest Harmonious Subsequence

func findLHS(nums []int) int {
	mm := map[int]int{}

	res := 0
	for _, num := range nums {
		mm[num]++
		freq := mm[num]
		if m, ok := mm[num+1]; ok {
			if freq+m > res {
				res = freq + m
			}
		}

		if m, ok := mm[num-1]; ok {
			if freq+m > res {
				res = freq + m
			}
		}
	}

	return res
}
