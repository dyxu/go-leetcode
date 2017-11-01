#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		std::vector<int> pv(26, 0), sv(26, 0), res;
		if (s.size() < p.size()) return res;
		for (int i = 0; i < p.size(); ++i) {
			++pv[p[i]-'a'];
			++sv[s[i]-'a'];
		}
		if (pv == sv) {
			res.push_back(0);
		}

		for (int i = p.size(); i < s.size(); ++i) {
			++sv[s[i]-'a'];
			--sv[s[i-p.size()]-'a'];
			if (pv == sv) {
				res.push_back(i-p.size()+1);
			}
		}

		return res;
    }
};

int main() {
	Solution s;
	s.findAnagrams("abababab", "ab");
	return 0;
}
