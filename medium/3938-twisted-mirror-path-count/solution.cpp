#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        // Optimization: Fast I/O execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        // 1. O(N) Space DP Array: Maps paths falling DOWN into the current row
        vector<long long> dp_down(n, 0);

        // 2. Hardware-Aligned L1 Cache Sweep
        for (int r = 0; r < m; ++r) {
            
            // Scalar mapping paths moving RIGHT into the current column
            long long dp_right = 0;

            for (int c = 0; c < n; ++c) {
                // Accumulate converging vectors
                long long ways_in = (dp_right + dp_down[c]) % MOD;

                // Absolute origin injection
                if (r == 0 && c == 0) {
                    ways_in = 1;
                }

                if (grid[r][c] == 0) {
                    // Terminal Extraction: Destination Reached
                    if (r == m - 1 && c == n - 1) {
                        return ways_in;
                    }
                    
                    // Empty Cell: Split the stream into new Right and Down branches
                    dp_right = ways_in;
                    dp_down[c] = ways_in;
                    
                } else {
                    // 3. Mirror Redirection
                    // In-place momentum swap. No paths terminate, they just re-route.
                    long long next_dp_down = dp_right;
                    long long next_dp_right = dp_down[c];
                    
                    dp_right = next_dp_right;
                    dp_down[c] = next_dp_down;
                }
            }
        }

        return 0;
    }
};