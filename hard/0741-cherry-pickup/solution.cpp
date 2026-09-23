class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1e9));
        if (grid[0][0] != -1) {
            dp[0][0] = grid[0][0];
        }
        for (int t = 1; t <= 2 * n - 2; ++t) {
            
            for (int r1 = min(n - 1, t); r1 >= max(0, t - n + 1); --r1) {
                for (int r2 = min(n - 1, t); r2 >= max(0, t - n + 1); --r2) {
                    int c1 = t - r1;
                    int c2 = t - r2;

                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) {
                        dp[r1][r2] = -1e9;
                        continue;
                    }
                    int val = dp[r1][r2]; 
                    if (r1 > 0) val = max(val, dp[r1 - 1][r2]);
                    if (r2 > 0) val = max(val, dp[r1][r2 - 1]);
                    if (r1 > 0 && r2 > 0) val = max(val, dp[r1 - 1][r2 - 1]); 
                    if (val < 0) {
                        dp[r1][r2] = -1e9;
                        continue;
                    }
                    val += grid[r1][c1];
                    if (r1 != r2) {
                        val += grid[r2][c2]; 
                    }

                    dp[r1][r2] = val;
                }
            }
        }

        return max(0, dp[n - 1][n - 1]);
    }
};