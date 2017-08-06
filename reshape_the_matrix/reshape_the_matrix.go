package reshape_the_matrix

// 566. Reshape the Matrix

func matrixReshape(nums [][]int, r int, c int) [][]int {
	row, col := len(nums), len(nums[0])
	if row*col != r*c {
		return nums
	}
	res := make([][]int, r)
	rr, cc := 0, 0
	for i := 0; i < r; i++ {
		res[i] = make([]int, c)
		for j := 0; j < c; j++ {
			res[i][j] = nums[rr][cc]
			cc++
			if cc == col {
				cc = 0
				rr++
			}
		}
	}

	return res
}
