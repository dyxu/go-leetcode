package remove_duplicate_letters

//package main

import "fmt"

// 316. Remove Duplicate Letters

func removeDuplicateLetters(s string) string {
	counts := [26]int{}
	for _, ch := range s {
		counts[ch-'a']++
	}

	fmt.Printf("%v\n", counts)

	return s
}

func main() {
	s := "cbacdcbc"
	removeDuplicateLetters(s)
}
