class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        pass
# dp[i][j] = max(dp[i][j], nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j])