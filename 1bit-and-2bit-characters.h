#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
		bool ok;
		for (size_t i = 0;  i < bits.size();) {
			if (bits[i]) {
				ok = false;
				i += 2;
			} else {
				ok = true;
				++i;
			}
		}

		return ok;
    }
};
