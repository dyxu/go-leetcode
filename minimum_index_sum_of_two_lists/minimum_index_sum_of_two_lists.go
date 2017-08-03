package minimum_index_sum_of_two_lists

import (
	"math"
)

// 599. Minimum Index Sum of Two Lists

func findRestaurant(list1 []string, list2 []string) []string {
	mm := map[string]int{}
	for i, v := range list1 {
		mm[v] = i
	}

	min := math.MaxInt64
	res := []string{}
	for i, v := range list2 {
		if idx, ok := mm[v]; ok {
			if idx+i <= min {
				if min == idx+i {
					res = append(res, v)
				} else {
					res = []string{v}
				}
				min = idx + i
			}

		}
	}

	return res
}
