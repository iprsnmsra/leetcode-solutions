#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = coins.size();
        int n = coins[0].size();
        const int MIN_VAL = -1e9; 
        vector<vector<int>> dp(n, vector<int>(3, MIN_VAL));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp[0][0] = coins[0][0];
                    dp[0][1] = coins[0][0] < 0 ? 0 : coins[0][0];
                    dp[0][2] = coins[0][0] < 0 ? 0 : coins[0][0];
                    continue;
                }
                vector<int> curr(3, MIN_VAL);
                int val = coins[i][j];
                for (int k = 0; k <= 2; ++k) {
                    
                    int prev_max = MIN_VAL;
                    if (i > 0) prev_max = max(prev_max, dp[j][k]);
                    if (j > 0) prev_max = max(prev_max, dp[j-1][k]);
                    if (prev_max != MIN_VAL) {
                        curr[k] = max(curr[k], prev_max + val);
                    }
                    if (val < 0 && k > 0) {
                        int prev_k_max = MIN_VAL;
                        if (i > 0) prev_k_max = max(prev_k_max, dp[j][k-1]);
                        if (j > 0) prev_k_max = max(prev_k_max, dp[j-1][k-1]);
                        if (prev_k_max != MIN_VAL) {
                            curr[k] = max(curr[k], prev_k_max);
                        }
                    }
                }
                dp[j] = curr;
            }
        }
        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};