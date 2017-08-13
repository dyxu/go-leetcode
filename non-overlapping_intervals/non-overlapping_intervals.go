package non_overlapping_intervals

// 435. Non-overlapping Intervals

import (
	"sort"
)

// Definition for an interval.
type Interval struct {
	Start int
	End   int
}

type Slice []Interval

func (s Slice) Len() int {
	return len(s)
}

func (s Slice) Less(i, j int) bool {
	return s[i].End < s[j].End
}

func (s Slice) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func eraseOverlapIntervals(intervals []Interval) int {
	cnt, m, n := 1, 0, len(intervals)
	if n < 2 {
		return 0
	}

	s := Slice(intervals)
	sort.Sort(s)

	for i := 1; i < n; i++ {
		if intervals[i].Start >= intervals[m].End {
			cnt++
			m = i
		}
	}

	return n - cnt
}
