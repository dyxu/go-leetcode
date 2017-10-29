#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		int max_area = 0;
		for (size_t r = 0; r < grid.size(); r++) {
			for (size_t c = 0; c < grid[0].size(); c++) {
				if (grid[r][c] == 1) {
					max_area = std::max(max_area, areaOfIsland(grid, r, c));
				}
			}
		}

		return max_area;
    }

	int areaOfIsland(vector<vector<int>>& grid, int r, int c) {
		if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1) {
			grid[r][c] = 0;
			return 1 + areaOfIsland(grid, r - 1, c) + areaOfIsland(grid, r + 1, c) +
				areaOfIsland(grid, r, c - 1) + areaOfIsland(grid, r, c + 1);
		}

		return 0;
	}
};
