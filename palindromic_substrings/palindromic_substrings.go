package palindromic_substrings

func countSubstrings(s string) int {
	if len(s) <= 0 {
		return 0
	}

	cnt := 0
	for i := range s {
		cnt += extendPalindrome(s, i, i)
		cnt += extendPalindrome(s, i, i+1)
	}

	return cnt
}

func extendPalindrome(s string, left, right int) int {
	cnt := 0
	for left >= 0 && right < len(s) && s[left] == s[right] {
		cnt++
		left--
		right++
	}

	return cnt
}
