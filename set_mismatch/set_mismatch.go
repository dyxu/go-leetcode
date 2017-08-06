package set_mismatch

// 645. Set Mismatch

func findErrorNums(nums []int) []int {
	twice, miss := 0, 0
	set := make([]int, len(nums))
	for _, x := range nums {
		if set[x-1] == x {
			twice = x
		}
		set[x-1] = x
	}

	for i, x := range set {
		if x == 0 {
			miss = i + 1
		}
	}

	return []int{twice, miss}
}
