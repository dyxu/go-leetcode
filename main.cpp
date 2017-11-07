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
    Solution(vector<int> nums) {
		for (size_t i = 0; i < nums.size(); i++) {
			auto iter = index.find(nums[i]);
			if (iter == index.end()) {
				index[nums[i]] = vector<size_t>(1, i);
			} else {
				iter->second.push_back(i);
			}
		}
    }

    int pick(int target) {
		auto idx = index.find(target);
		return idx->second[std::rand() %  idx->second.size()];
    }
private:
	unordered_map<int, vector<size_t>> index;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

int main() {
	vector<int> nums = {1, 2, 3, 3, 3};
	Solution s(nums);
	cout << s.pick(3) << endl;

	return 0;
}
