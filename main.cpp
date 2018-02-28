#include <iostream>
#include <sstream>
#include <limits>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T>
void Traversal(T& container) {
	typename T::const_iterator first = container.begin(), last = container.end();
	std::cout << "[";
	while (first != last) {
		std::cout << *first;
		if (++first != last) {
			std::cout << ", ";
		}
	}
	std::cout << "]" << std::endl;
}

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
		int n = nums.size(), res = 0, max_len = 0;
		vector<std::pair<int, int>> dp(n, {1, 1});
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < i; k++) {
				if (nums[i] > nums[k]) {
					if (dp[i].first == dp[k].first + 1) {
						dp[i].second += dp[k].second;
					}
					if (dp[i].first < dp[k].first + 1) {
						dp[i] = {dp[k].first + 1, dp[k].second};
					}
				}
			}

			if (max_len == dp[i].first) {
				res += dp[i].second;
			}
			if (max_len < dp[i].first) {
				max_len = dp[i].first;
				res = dp[i].second;
			}
		}

		return res;
    }
};

int main() {
	Solution s;
	vector<string> res;
	Traversal(res);
    
	return 0;
}
