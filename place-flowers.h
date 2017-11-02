#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
		for (int i = 0; i < bed.size(); i++) {
			if (!bed[i] && (i == 0 || !bed[i-1]) && (i == bed.size()-1 || !bed[i+1])) {
				bed[i] = 1;
				n--;
			}
		}

		return n <= 0;
    }
};
