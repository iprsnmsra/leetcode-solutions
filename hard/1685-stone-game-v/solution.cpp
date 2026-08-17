#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = stoneValue.size();
        if (n <= 1) return 0;
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        vector<int> dp(n * n, 0);

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                int max_score = 0;
                for (int k = i; k < j; ++k) {
                    int left_sum = pref[k + 1] - pref[i];
                    int right_sum = pref[j + 1] - pref[k + 1];
                    if (left_sum < right_sum) {
                        max_score = max(max_score, left_sum + dp[i * n + k]);
                    } else if (left_sum > right_sum) {
                        max_score = max(max_score, right_sum + dp[(k + 1) * n + j]);
                    } else {
                        max_score = max({max_score, 
                                         left_sum + dp[i * n + k], 
                                         right_sum + dp[(k + 1) * n + j]});
                    }
                }
                dp[i * n + j] = max_score;
            }
        }
        return dp[0 * n + (n - 1)];
    }
};