#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
		if (chars.empty()) return 0;
		int n = chars.size(), idx = 0, cnt = 1;
		for (int i = 1; i < n; i++) {
			if (chars[idx] != chars[i] || i == n - 1) {
				bool equal = false;
				if (chars[idx] == chars[i]) {
					equal = true;
					cnt++;
				}
				if (cnt > 1 && cnt < 10) {
					chars[++idx] = '0' + cnt;
				} else if (cnt >= 10) {
					string str = to_string(cnt);
					for (auto ch: str) {
						chars[++idx] = ch;
					}
				}
				if (!equal) {
					chars[++idx] = chars[i];
				}
				cnt = 1;
			} else {
				cnt++;
			}
		}

		return idx + 1;
    }
};

int main() {
	Solution s;
	vector<vector<char>> test_cases = {
		{},
		{'a'},
		{'a', 'b'},
		{'a', 'b', 'b'},
		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b'},
		{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'},
	};

	for (auto chars: test_cases) {
		int n = s.compress(chars);
		cout << "size=" << n << " chars=[";
		for (int i = 0; i < n; i++) {
			cout << chars[i] << " ";
		}
		cout << "]" << endl;
	}
	return 0;
}
