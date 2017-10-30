#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, int> map, startIdx;
		int n = nums.size(), degree = 0, res = numeric_limits<int>::max();
		for (int i = 0; i < n; i++) {
			if (startIdx.find(nums[i]) == startIdx.end()) {
				startIdx[nums[i]] = i;
			}
			int d = ++map[nums[i]];
			if (d == degree) {
				res = min(res, i - startIdx[nums[i]] + 1);
			} else if (d > degree) {
				res = i - startIdx[nums[i]] + 1;
				degree = d;
			}
		}

		return res;
    }
};
