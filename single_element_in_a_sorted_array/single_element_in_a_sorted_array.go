package single_element_in_a_sorted_array

func singleNonDuplicate(nums []int) int {
	left, right := 0, len(nums)/2
	for left < right {
		mid := (left + right) / 2
		if nums[2*mid] != nums[2*mid+1] {
			right = mid
		} else {
			left = mid + 1
		}
	}

	return nums[2*left]
}
