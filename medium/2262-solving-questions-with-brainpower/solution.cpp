#include <vector>
#include <algorithm>
#include <iostream>
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            int points = questions[i][0];
            int brainpower = questions[i][1];
            int next_available_idx = i + brainpower + 1;long long solve_score = points;
            if (next_available_idx < n) {
                solve_score += dp[next_available_idx]; 
            }
            long long skip_score = dp[i + 1];
            dp[i] = max(solve_score, skip_score);
        }
        return dp[0];
    }
};