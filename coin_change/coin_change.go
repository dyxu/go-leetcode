package coin_change

func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)

	for i := range dp {
		dp[i] = amount + 1
	}
	dp[0] = 0

	for i := 1; i <= amount; i++ {
		for _, c := range coins {
			if c <= i {
				if dp[i] > dp[i-c]+1 {
					dp[i] = dp[i-c] + 1
				}
			}
		}
	}

	if dp[amount] > amount {
		return -1
	}

	return dp[amount]
}
