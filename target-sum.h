#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
		return help(nums, 0, S);
    }
	int help(vector<int>& nums, size_t idx, int sum) {
		if (idx == nums.size()) {
			if (sum == 0) {
				return 1;
			} else {
				return 0;
			}
		}

		return help(nums, idx+1, sum+nums[idx]) + help(nums, idx+1, sum-nums[idx]);
	}
};
