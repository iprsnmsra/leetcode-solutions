#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        int valid_islands = 0;

        // 4-directional adjacency offsets
        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        // 1. Pre-allocated flat queue to prevent recursion stack overflow
        // Reserving m * n guarantees zero dynamic reallocation stalls during BFS.
        vector<pair<int, int>> q;
        q.reserve(m * n);

        // 2. Linear Matrix Sweep
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] > 0) {
                    // 3. 64-Bit Sum Register (Prevents integer overflow for sums up to 10^11)
                    long long island_sum = 0;

                    // Start BFS for the newly discovered island component
                    q.clear();
                    q.push_back({r, c});
                    island_sum += grid[r][c];
                    grid[r][c] = 0; // Immediate sinking prevents duplicate visits

                    int head = 0;
                    while (head < (int)q.size()) {
                        auto [curr_r, curr_c] = q[head++];

                        for (int i = 0; i < 4; ++i) {
                            int nr = curr_r + dr[i];
                            int nc = curr_c + dc[i];

                            // Bounds and land check
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                island_sum += grid[nr][nc];
                                grid[nr][nc] = 0; // Sink land immediately upon queueing
                                q.push_back({nr, nc});
                            }
                        }
                    }

                    // 4. Modulo Divisibility Check
                    if (island_sum % k == 0) {
                        valid_islands++;
                    }
                }
            }
        }

        return valid_islands;
    }
};