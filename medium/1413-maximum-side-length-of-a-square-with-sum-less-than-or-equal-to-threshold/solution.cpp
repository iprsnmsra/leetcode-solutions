#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = mat.size();
        int n = mat[0].size();
        
        // Use a 2D DP array (1-based indexing to avoid boundary checks)
        // dp[i][j] = Sum of rectangle from (0,0) to (i-1, j-1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int max_side = 0;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 1. Build the 2D Prefix Sum
                // Current val + Top + Left - TopLeft (to remove double count)
                dp[i][j] = mat[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

                // 2. Greedy Check
                // We want to see if we can form a square of size (max_side + 1)
                // The bottom-right corner is current (i, j).
                int target = max_side + 1;
                
                // Ensure the indices are valid for the target size
                if (i >= target && j >= target) {
                    // Calculate sum of square of size 'target' ending at (i, j)
                    int sum = dp[i][j] 
                            - dp[i - target][j] 
                            - dp[i][j - target] 
                            + dp[i - target][j - target];
                    
                    if (sum <= threshold) {
                        max_side = target;
                    }
                }
            }
        }

        return max_side;
    }
};