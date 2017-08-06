package base_7

import (
	"strconv"
)

// 504. Base 7

func convertToBase7(num int) string {
	if num == 0 {
		return "0"
	}

	res, pos := "", true
	if num < 0 {
		num = -num
		pos = false
	}

	for num != 0 {
		res = strconv.Itoa(num%7) + res
		num /= 7
	}

	if !pos {
		return "-" + res
	}

	return res
}
