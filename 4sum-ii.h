#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> mm;
		for (auto a: A) {
			for (auto b: B) {
				++mm[a+b];
			}
		}

		int cnt = 0;
		for (auto c: C) {
			for (auto d: D) {
				auto iter = mm.find(0-c-d);
				if (iter != mm.end()) {
					cnt += iter->second;
				}
			}
		}

		return cnt;
    }
};
