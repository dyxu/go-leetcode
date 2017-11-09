#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <unordered_map>

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
	std::cout << "]" << endl;
}

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

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main() {
	vector<int> nums = {1, 2, 3, 3, 3};
	Solution s(nums);

	return 0;
}
