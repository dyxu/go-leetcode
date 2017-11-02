#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
		long base = 9;
		int k = 1, start = 1;
		while (n > k * base) {
			n -= base * k;
			base *= 10;
			start *= 10;
			k++;
		}

		start += (n - 1) / k;
		return to_string(start).at((n-1)%k) - '0';
    }
};
