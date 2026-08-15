#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        vector<long long> max_dp(n);
        vector<long long> min_dp(n);

        max_dp[0] = min_dp[0] = grid[0][0];

        for (int c = 1; c < n; ++c) {
            max_dp[c] = min_dp[c] = max_dp[c - 1] * grid[0][c];
        }

        for (int r = 1; r < m; ++r) {

            max_dp[0] *= grid[r][0];
            min_dp[0] *= grid[r][0];
            
            for (int c = 1; c < n; ++c) {
                long long prev_max = max(max_dp[c], max_dp[c - 1]);
                long long prev_min = min(min_dp[c], min_dp[c - 1]);

                if (grid[r][c] < 0) {
                    max_dp[c] = prev_min * grid[r][c];
                    min_dp[c] = prev_max * grid[r][c];
                } else {
                    max_dp[c] = prev_max * grid[r][c];
                    min_dp[c] = prev_min * grid[r][c];
                }
            }
        }

        if (max_dp[n - 1] < 0) {
            return -1;
        }

        return max_dp[n - 1] % MOD;
    }
};