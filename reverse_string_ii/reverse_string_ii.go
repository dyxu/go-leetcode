package reverse_string_ii

// 541. Reverse String II

func reverseStr(s string, k int) string {
	ss := []rune(s)
	prev, curr, n := 0, 0, len(s)

	cnt := 1
	for curr < n {
		if cnt == k || (curr == n-1 && cnt <= k) {
			for i, j := prev, curr; i < j; {
				ss[i], ss[j] = ss[j], ss[i]
				i++
				j--
			}
			prev = curr + 1 + k
			cnt = 0
		}
		curr++
		cnt++
	}

	return string(ss)
}
