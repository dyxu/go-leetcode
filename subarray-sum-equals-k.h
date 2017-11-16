#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		int cum = 0, res = 0;
		unordered_map<int, int> mm;
		mm[0]++;
		for (auto num: nums) {
			cum += num;
			res += mm[cum - k];
			mm[cum]++;
		}

		return res;
    }
};
