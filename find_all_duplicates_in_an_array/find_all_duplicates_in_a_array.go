package find_all_duplicates_in_an_array

func findDuplicates(nums []int) []int {
	res := []int{}
	for _, v := range nums {
		if v < 0 {
			v = -v
		}

		if nums[v-1] < 0 {
			res = append(res, v)
		} else {
			nums[v-1] *= -1
		}
	}

	return res
}
