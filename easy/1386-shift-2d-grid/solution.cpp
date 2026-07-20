#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        int total_cells = m * n;
        k = k % total_cells;
        if (k == 0) return grid;
        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int flat_index = r * n + c;
                int new_flat_index = (flat_index + k) % total_cells;
                int new_r = new_flat_index / n;
                int new_c = new_flat_index % n;
                result[new_r][new_c] = grid[r][c];
            }
        }

        return result;
    }
};