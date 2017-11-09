#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums): nums_(nums) { }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
		return nums_;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
		vector<int> res(nums_);
		int n = res.size();
		for (int i = 0; i < res.size(); ++i) {
			int pos = std::rand() % (n - i);
			std::swap(res[i+pos], res[i]);
		}

		return res;
    }
private:
	vector<int> nums_;
};
