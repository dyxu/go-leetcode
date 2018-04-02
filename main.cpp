#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

std::vector<int> ReadAll(string filename) {
	std::vector<int> nums;
	string line;
	std::ifstream fin(filename);
	while (fin >> line) {
		int num = std::atoi(line.c_str());
		nums.push_back(num);
	}

	return nums;
}

std::vector<int> TopN(std::vector<int>& nums, int n) {
	std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
	for (int i = 0; i < nums.size(); i++) {
		if (i < n) {
			min_heap.push(nums[i]);
		} else {
			if (nums[i] >= min_heap.top()) {
				min_heap.pop();
				min_heap.push(nums[i]);
			}
		}
	}

	std::vector<int> res(min_heap.size());
	for (int i = min_heap.size() - 1; i >= 0; i--) {
		res[i] = min_heap.top();
		min_heap.pop();
	}

	return res;
}


int main() {
	vector<int> nums{3, 2, 1, 5, 3, 6, 5};
	vector<int> res;
	res = TopN(nums, 5);
	for (auto num: res) {
		cout << num << endl;
	}
	return 0;
}
