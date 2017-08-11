package maximum_length_of_pair_chain

import (
	"sort"
)

// 646. Maximum Length of Pair Chain

type Slice [][]int

func (s Slice) Len() int {
	return len(s)
}

func (s Slice) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s Slice) Less(i, j int) bool {
	return s[i][1] < s[j][1]
}

func findLongestChain(pairs [][]int) int {
	ps := Slice(pairs)
	sort.Sort(ps)
	cnt, m := 1, 0
	for k, pair := range pairs {
		if pair[0] > pairs[m][1] {
			m = k
			cnt++
		}
	}

	return cnt
}
