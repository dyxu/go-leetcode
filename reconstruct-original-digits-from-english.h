class Solution {
public:
    string originalDigits(string s) {
		vector<int> counts(10);
		for (char ch: s) {
			switch (ch) {
			case 'z': counts[0]++; break;
			case 'w': counts[2]++; break;
			case 'x': counts[6]++; break;
			case 's': counts[7]++; break; // 7-6
			case 'g': counts[8]++; break;
			case 'u': counts[4]++; break;
			case 'f': counts[5]++; break; // 5-4
			case 'h': counts[3]++; break; // 3-8
			case 'i': counts[9]++; break; // 9-8-5-6
			case 'o': counts[1]++; break; // 1-0-2-4
			}
		}

		counts[7] -= counts[6];
		counts[5] -= counts[4];
		counts[3] -= counts[8];
		counts[9] = counts[9] - counts[8] - counts[5] - counts[6];
		counts[1] = counts[1] - counts[0] - counts[2] - counts[4];

		stringstream ss;
		for (int i = 0; i < 10; i++) {
			while (counts[i]--) {
				ss << i;
			}
		}

		return ss.str();
    }
};
