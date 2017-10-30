#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		if (M.empty()) return M;
		vector<int> dx{-1, 0, 1, -1, 1, -1, 0, 1}, dy{-1, -1, -1, 0, 0, 1, 1, 1};
		vector<vector<int>> matrix(M.size(), vector<int>(M[0].size()));
		int row = M.size(), col = M[0].size();
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				int cnt = 1, sum = M[r][c];
				for (int k = 0; k < 8; k++) {
					int x = c + dx[k], y = r + dy[k];
					if (0 <= x && x < col && 0 <= y && y < row) {
						cnt++;
						sum += M[y][x];
					}
				}
				matrix[r][c] = sum / cnt;
			}
		}

		return matrix;
    }
};
