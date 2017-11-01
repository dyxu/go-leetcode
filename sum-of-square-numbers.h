#include <iostream>
#include <cmath>
#include <set>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
		if (c < 0) return false;
		int left = 0, right = static_cast<int>(std::sqrt(c));
		while (left <= right) {
			int curr = left * left + right * right;
			if (curr < c) {
				left++;
			} else if (curr > c) {
				right--;
			} else {
				return true;
			}
		}

		return false;
    }
};

int main() {
	Solution s;
	cout << s.judgeSquareSum(3) << endl;
	return 0;
}
