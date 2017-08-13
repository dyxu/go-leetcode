package wiggle_subsequence

// 376. Wiggle Subsequence

// func wiggleMaxLength(nums []int) int {
// 	n := len(nums)
// 	if n < 2 {
// 		return n
// 	}

// 	prev := nums[1] - nums[0]
// 	cnt := 2
// 	if prev == 0 {
// 		cnt = 1
// 	}

// 	for i := 2; i < n; i++ {
// 		curr := nums[i] - nums[i-1]
// 		if (curr > 0 && prev <= 0) || (curr < 0 && prev >= 0) {
// 			cnt++
// 			prev = curr
// 		}
// 	}

// 	return cnt
// }

func wiggleMaxLength(nums []int) int {
	n := len(nums)
	if n < 2 {
		return n
	}

	p, q := 1, 1
	for i := 1; i < n; i++ {
		if nums[i]-nums[i-1] > 0 {
			p = q + 1
		}

		if nums[i]-nums[i-1] < 0 {
			q = p + 1
		}
	}

	if p > q {
		return p
	}

	return q
}
