#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }
        int fish = grid[r][c];
        grid[r][c] = 0;
        fish += dfs(grid, r + 1, c, m, n);
        fish += dfs(grid, r - 1, c, m, n);
        fish += dfs(grid, r, c + 1, m, n);
        fish += dfs(grid, r, c - 1, m, n);

        return fish;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        int max_yield = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    max_yield = max(max_yield, dfs(grid, i, j, m, n));
                }
            }
        }

        return max_yield;
    }
};