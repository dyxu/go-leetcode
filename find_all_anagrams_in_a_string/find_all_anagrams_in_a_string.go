package find_all_anagrams_in_a_string

// 438. Find All Anagrams in a String

func findAnagrams(s string, p string) []int {
	freq := [24]int{}
	for _, ch := range p {
		freq[ch-'a']++
	}

	mm, cnt := freq, len(p)
	for i, ch := range s {
		if freq[ch-'a']
	}
}
