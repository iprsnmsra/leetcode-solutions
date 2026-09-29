#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        
        // 1. O(1) Mathematical Fast Fails
        // A balanced string MUST have an even length.
        if ((m + n - 1) % 2 != 0) return false;
        
        // It MUST start with an opening bracket and end with a closing bracket.
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        // 2. Data Abstraction: 1D Array of Hardware Registers
        // The max path length is 199. The max recoverable open balance is 99.
        // A 105-bit bitset perfectly covers the valid state space.
        vector<bitset<105>> dp(n);
        
        // Base state origin: starting at (0,0) yields a balance of exactly 1
        dp[0].set(1); 

        // 3. The 2D DP Forward Sweep
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                // Combine possible arriving balances from the Top and Left cells
                bitset<105> prev;
                if (i > 0) prev |= dp[j];
                if (j > 0) prev |= dp[j - 1];

                // 4. Dimensional Collapse via Hardware Shifting
                if (grid[i][j] == '(') {
                    // Increment all possible balances simultaneously (Shift Left)
                    dp[j] = prev << 1;
                } else {
                    // Decrement all possible balances simultaneously (Shift Right)
                    // Any balance that was 0 shifts completely off the bitset natively, 
                    // flawlessly simulating the failure state of negative balance.
                    dp[j] = prev >> 1;
                }
            }
        }

        // 5. State Extraction
        // Returns true if a balance of exactly 0 is achievable at the bottom-right corner.
        return dp[n - 1][0];
    }
};