#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		auto iter = nums.begin() + nums.size() / 2;
		std::nth_element(nums.begin(), iter, nums.end());
		int median = *iter, total = 0;
		for (auto num: nums) {
			total += std::abs(num - median);
		}

		return total;
	}
};
