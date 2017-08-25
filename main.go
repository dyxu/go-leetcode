package main

import (
	"fmt"
	"sort"
)

type pairs [][]int

func (p pairs) Len() int {
	return len(p)
}

func (p pairs) Less(i, j int) bool {
	return p[i][0] > p[j][0] || (p[i][0] == p[j][0] && p[i][1] < p[j][1])
}

func (p pairs) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func reconstructQueue(people [][]int) [][]int {
	sort.Sort(pairs(people))
	res := make([][]int, len(people))
	end := 0
	for _, p := range people {
		for i := end; i > p[1]; i-- {
			res[i] = res[i-1]
		}

		res[p[1]] = p
		end++
	}

	return res
}

func main() {
	people := [][]int{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {7, 1}}
	fmt.Printf("%v\n", reconstructQueue(people))
}
