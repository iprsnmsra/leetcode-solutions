#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = jobDifficulty.size();

        if (n < d) return -1;

        vector<int> dp(n, 1e9);

        int current_max = 0;
        for (int i = 0; i < n; ++i) {
            current_max = max(current_max, jobDifficulty[i]);
            dp[i] = current_max;
        }

        for (int day = 2; day <= d; ++day) {

            vector<int> next_dp(n, 1e9);

            for (int i = day - 1; i < n; ++i) {
                int daily_max = 0;

                for (int j = i; j >= day - 1; --j) {

                    daily_max = max(daily_max, jobDifficulty[j]);

                    next_dp[i] = min(next_dp[i], dp[j - 1] + daily_max);
                }
            }

            dp = next_dp;
        }

        return dp[n - 1];
    }
};