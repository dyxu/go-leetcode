#include <iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
		return valid(s, 0, s.size() - 1, 1);
    }
private:
	bool valid(string& s, int l, int r, int del) {
		if (l >= r) return true;
		if (s[l] == s[r]) {
			return valid(s, l+1, r-1, del);
		} else {
			return del > 0 && (valid(s, l, r-1, del-1) || valid(s, l+1, r, del-1));
		}
	}
};

int main() {
	Solution s;
	cout << s.validPalindrome("abca") << endl;
	return 0;
}
