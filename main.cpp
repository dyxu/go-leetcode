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


int main() {
	vector<int> nums = {1, 2, 3, 3, 3};
	Solution s(nums);
	cout << s.pick(3) << endl;

	return 0;
}
