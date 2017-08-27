package maximum_product_of_word_lengths

func maxProduct(words []string) int {
	mask := make([]int, len(words))

	res := 0
	for i, w := range words {
		for _, ch := range w {
			mask[i] |= 1 << uint8(ch-'a')
		}

		for j := 0; j < i; j++ {
			if (mask[i] & mask[j]) == 0 {
				prod := len(words[i]) * len(words[j])
				if prod > res {
					res = prod
				}
			}
		}
	}

	return res
}
