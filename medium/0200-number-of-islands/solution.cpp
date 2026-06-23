#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (grid.empty()) return 0;

        int num_islands = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                if (grid[i][j] == '1') {
                    num_islands++;

                    sinkIsland(grid, i, j, m, n);
                }
            }
        }

        return num_islands;
    }

private:
    void sinkIsland(vector<vector<char>>& grid, int i, int j, int m, int n) {

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';
        sinkIsland(grid, i + 1, j, m, n); 
        sinkIsland(grid, i - 1, j, m, n); 
        sinkIsland(grid, i, j + 1, m, n); 
        sinkIsland(grid, i, j - 1, m, n); 
    }
};