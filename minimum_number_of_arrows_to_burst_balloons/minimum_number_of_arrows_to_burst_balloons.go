package minimum_number_of_arrows_to_burst_balloons

import (
	"math"
	"sort"
)

// 452. Minimum Number of Arrows to Burst Balloons

type pairs [][]int

func (p pairs) Len() int {
	return len(p)
}

func (p pairs) Less(i, j int) bool {
	return p[i][1] < p[j][1]
}

func (p pairs) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func findMinArrowShots(points [][]int) int {
	if len(point) <= 1 {
		return len(points)
	}
	sort.Sort(pairs(points))
	cnt, max := 0, -math.MaxInt32
	for _, point := range points {
		if point[0] > max {
			max = point[1]
			cnt++
		}
	}

	return cnt
}
