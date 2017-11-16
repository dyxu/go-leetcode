#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
		int total = 0, n = nums.size();
		for (int off = 0; off < 32; off++) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if ((nums[i] >> off) & 0x01)
					cnt ++;
			}
			total += cnt * (n - cnt);
		}

		return total;
    }
};
