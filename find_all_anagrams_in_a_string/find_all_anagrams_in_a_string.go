// package find_all_anagrams_in_a_string

package main

import "fmt"

// 438. Find All Anagrams in a String

func findAnagrams(s string, p string) []int {
	res := []int{}
	if len(s) == 0 || len(p) == 0 {
		return res
	}

	hash := [256]int{}
	for _, ch := range p {
		hash[ch]++
	}

	cnt, n := len(p), len(p)
	for left, right := 0, 0; right < len(s); right++ {
		if hash[s[right]] >= 1 {
			hash[s[right]]--
			cnt--
		}

		if cnt == 0 {
			res = append(res, left)
		}

		if right-left+1 == n && hash[s[left]] >= 0 {
			hash[s[left]]++
			left++
			cnt++
		}
	}

	return res
}

func main() {
	fmt.Printf("%v\n", findAnagrams("cbaebabacd", "abc"))
}
