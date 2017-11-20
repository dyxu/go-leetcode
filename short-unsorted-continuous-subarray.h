class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
		vector<int> order(nums);
		int n = nums.size(), i = 0, j = n - 1;

		std::sort(order.begin(), order.end());
		while (i < n && nums[i] == order[i]) i++;
		while (i < j && nums[j] == order[j]) j--;

		return j - i + 1;
    }
};
