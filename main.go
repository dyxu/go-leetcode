package main

import (
	"fmt"
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
	p := Slice(pairs)
	sort.Sort(p)
	fmt.Printf("%v\n", p)
	fmt.Printf("%v\n", pairs)

	return 0
}

func main() {
	ss := [][]int{{1, 2}, {2, 1}, {3, 0}}
	findLongestChain(ss)
}
