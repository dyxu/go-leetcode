class Solution {
public:
    int minSteps(int n) {
		if (n == 1) return 0;
		for (int k = 2; k < n; k++) {
			if (n % k == 0) return k + minSteps(n / k);
		}

		return n;
    }

};
