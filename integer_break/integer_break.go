package integer_break

import (
	"math"
)

// 343. Integer Break

func integerBreak(n int) int {
	if n == 2 || n == 3 {
		return n - 1
	}

	if n == 4 {
		return 4
	}

	n -= 5

	return int(math.Pow(3.0, float64(n/3+1)) * float64(n%3+2))
}
