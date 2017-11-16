#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.empty()) return 0;
		int res = 0, n = timeSeries.size();
		for (int i = 1; i < n; i++) {
			int delta = timeSeries[i] - timeSeries[i-1];
			res += delta < duration ? delta: duration;
		}

		return res + duration;
    }
};
