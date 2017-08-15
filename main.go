package main

import (
	"fmt"
)

func isSubsequence(s string, t string) bool {
	idx, n := 0, len(s)
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

func main() {
	t, s := "ahbgdc", "abc"
	fmt.Printf("%v\n", isSubsequence(s, t))
	t, s = "ahbgdc", "axc"
	fmt.Printf("%v\n", isSubsequence(s, t))
}
