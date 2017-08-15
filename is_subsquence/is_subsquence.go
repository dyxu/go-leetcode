package is_subsquence

// 392. Is Subsequence

func isSubsequence(s string, t string) bool {
	idx, n := 0, len(s)
	if n <= 0 {
		return true
	}

	for i := range t {
		if t[i] == s[idx] {
			idx++
		}

		if idx == n {
			return true
		}
	}

	return false
}
