package maximum_average_subarray_i

import (
	"math"
)

// 643. Maximum Average Subarray I

func findMaxAverage(nums []int, k int) float64 {
	res := -math.MaxFloat64
	sum := 0.0
	for i, num := range nums {
		sum += float64(num)
		if i >= k {
			sum -= float64(nums[i-k])
		}

		if sum > res && i >= k-1 {
			res = sum
		}
	}

	return res / float64(k)
}
