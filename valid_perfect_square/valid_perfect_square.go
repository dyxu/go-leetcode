package valid_perfect_square

// 367. Valid Perfect Square

func isPerfectSquare(num int) bool {
	if num == 1 {
		return true
	}
	start, end := 1, num
	for start <= end {
		mid := start + (end-start)/2
		sqrt := mid * mid
		if sqrt == num {
			return true
		} else if sqrt < num {
			start = mid + 1
		} else {
			end = mid - 1
		}
	}
	return false
}
