#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
		unordered_map<char, int> freq;
		for (auto ch: s) {
			freq[ch]++;
		}
		vector<pair<char, int>> pairs;
		for (auto ele: freq) {
			pairs.push_back(ele);
		}
		std::sort(pairs.begin(), pairs.end(),
				  [](std::pair<char, int>& x, std::pair<char, int> y) {
					  return x.second > y.second;
				  });
		string res;
		for (auto ele: pairs) {
			for (int i = 0; i < ele.second; i++) {
				res.push_back(ele.first);
			}
		}

		return res;
	}
};

class Solution2 {
public:
    string frequencySort(string s) {
		unordered_map<char, int> freq;
		for (auto& ch: s) {
			freq[ch]++;
		}

		vector<string> bucket(s.size() + 1, "");
		for (auto& ele: freq) {
			bucket[ele.second].append(ele.second, ele.first);
		}
		string res;
		for (int i = bucket.size() - 1; i > 0; i--) {
			if (!bucket[i].empty()) {
				res.append(bucket[i]);
			}
		}

		return res;
	}
};
