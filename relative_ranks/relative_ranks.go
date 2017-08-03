package relative_ranks

import (
	"sort"
	"strconv"
)

// 506. Relative Ranks

func findRelativeRanks(nums []int) []string {
	mm := map[int]int{}
	res := make([]string, len(nums))
	for i, s := range nums {
		mm[s] = i
	}

	sort.Sort(sort.Reverse(sort.IntSlice(nums)))
	for i, v := range nums {
		if i == 0 {
			res[mm[v]] = "Gold Medal"
		} else if i == 1 {
			res[mm[v]] = "Silver Medal"
		} else if i == 2 {
			res[mm[v]] = "Bronze Medal"
		} else {
			res[mm[v]] = strconv.Itoa(i + 1)
		}
	}

	return res
}
