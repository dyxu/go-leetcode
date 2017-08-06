package poor_pigs

import (
	"math"
)

// 458. Poor Pigs

func poorPigs(buckets int, minutesToDie int, minutesToTest int) int {
	return int(math.Ceil(math.Log(float64(buckets)) / math.Log(float64(1+minutesToTest/minutesToDie))))
}
