#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	Solution(vector<int> nums): nums_(nums) {
	}

	int pick(int target) {
		int res = -1, cnt = 0;
		for (int i = 0; i < nums_.size(); i++) {
			if (target == nums_[i]) {
				cnt++;
				if (cnt == 1 || std::rand() % cnt == 0) {
					res = i;
				}
			}
		}

		return res;
	}
private:
	vector<int> nums_;
};
