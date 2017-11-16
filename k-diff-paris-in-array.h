class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
		std::map<int, int> freqs;
		for (int num: nums) {
			freqs[num]++;
		}

		int res = 0;
		for (auto& pair: freqs) {
			if (k == 0 && pair.second > 1) {
				res++;
			}

			if (k > 0 && freqs.find(pair.first+k) != freqs.end()) {
				res++;
			}
		}

		return res;
    }
};
