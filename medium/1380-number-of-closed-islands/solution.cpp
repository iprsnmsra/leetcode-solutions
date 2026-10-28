#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int rows;
    int cols;

    // Fast inline directional offsets for 4-way adjacency
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};

    // Destructive In-Place Flood Fill (Sinks Land '0' to Water '1')
    void sink(vector<vector<int>>& grid, int r, int c) {
        // Boundary and water check
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }

        // Mutate land directly to water to avoid auxiliary visited allocation
        grid[r][c] = 1;

        // Traverse 4-directional neighbors
        for (int i = 0; i < 4; ++i) {
            sink(grid, r + dx[i], c + dy[i]);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        rows = grid.size();
        cols = grid[0].size();

        // 1. Phase 1: Perimeter Annihilation
        // Sink all land connected to the outer boundary
        for (int r = 0; r < rows; ++r) {
            if (grid[r][0] == 0) sink(grid, r, 0);
            if (grid[r][cols - 1] == 0) sink(grid, r, cols - 1);
        }
        for (int c = 0; c < cols; ++c) {
            if (grid[0][c] == 0) sink(grid, 0, c);
            if (grid[rows - 1][c] == 0) sink(grid, rows - 1, c);
        }

        // 2. Phase 2: Interior Closed Island Counting
        int closed_islands = 0;
        for (int r = 1; r < rows - 1; ++r) {
            for (int c = 1; c < cols - 1; ++c) {
                if (grid[r][c] == 0) {
                    closed_islands++;
                    // Sink the entire closed island to prevent double-counting
                    sink(grid, r, c);
                }
            }
        }

        return closed_islands;
    }
};