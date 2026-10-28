#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();

        // 1. Memory Allocation: DP Table of 1024-bit sets
        // Each bitset natively consumes exactly 128 bytes of memory.
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));

        // 2. Base Case Initialization
        dp[0][0].set(grid[0][0]);

        // 3. Pre-compute Top Row Boundary
        for (int c = 1; c < n; ++c) {
            int val = grid[0][c];
            // To compute the new XOR states, we iterate over the active bits of the previous state
            for (int k = 0; k < 1024; ++k) {
                if (dp[0][c - 1].test(k)) {
                    dp[0][c].set(k ^ val);
                }
            }
        }

        // 4. Pre-compute Left Column Boundary
        for (int r = 1; r < m; ++r) {
            int val = grid[r][0];
            for (int k = 0; k < 1024; ++k) {
                if (dp[r - 1][0].test(k)) {
                    dp[r][0].set(k ^ val);
                }
            }
        }

        // 5. The Hardware-Accelerated DP Transition Sweep
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                int val = grid[r][c];
                
                // Union of all reachable XOR states from Top and Left in O(1) bitwise execution
                bitset<1024> prev_states = dp[r - 1][c] | dp[r][c - 1];

                // Propagate the XOR mutation forward
                for (int k = 0; k < 1024; ++k) {
                    if (prev_states.test(k)) {
                        dp[r][c].set(k ^ val);
                    }
                }
            }
        }

        // 6. Terminal State Extraction
        // Scan the bottom-right bitset for the absolute lowest possible set bit
        for (int i = 0; i < 1024; ++i) {
            if (dp[m - 1][n - 1].test(i)) {
                return i;
            }
        }

        return 0; // Unreachable fallback
    }
};