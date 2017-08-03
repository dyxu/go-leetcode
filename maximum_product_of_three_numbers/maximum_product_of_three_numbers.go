package maximum_product_of_three_numbers

import (
	"math"
)

// 628. Maximum Product of Three Numbers

func maximumProduct(nums []int) int {
	if len(nums) < 3 {
		return 0
	}
	max3 := []int{-math.MaxInt32, -math.MaxInt32, -math.MaxInt32}
	min2 := []int{math.MaxInt32, math.MaxInt32}

	for _, v := range nums {
		// find the max 3 num
		if v > max3[0] {
			max3[0] = v
			if max3[0] > max3[1] {
				max3[0], max3[1] = max3[1], max3[0]
				if max3[1] > max3[2] {
					max3[1], max3[2] = max3[2], max3[1]
				}
			}
		}

		// find the min 2 num
		if v < min2[1] {
			min2[1] = v
			if min2[1] < min2[0] {
				min2[0], min2[1] = min2[1], min2[0]
			}
		}
	}

	left := min2[0] * min2[1] * max3[2]
	right := max3[0] * max3[1] * max3[2]

	if left > right {
		return left
	}

	return right
}
