#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        if (n == 0) return 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 0)));

        for (int i = 0; i < n; ++i) {
            for (int rem = 0; rem <= k; ++rem) {
                dp[i][i][rem] = 1;
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                int diff = abs(s[i] - s[j]);
                int cost = min(diff, 26 - diff);

                for (int rem = 0; rem <= k; ++rem) {
                    int ans = max(dp[i + 1][j][rem], dp[i][j - 1][rem]);
                    if (rem >= cost) {
                        int inner_len = (len == 2) ? 0 : dp[i + 1][j - 1][rem - cost];
                        ans = max(ans, 2 + inner_len);
                    }
                    
                    dp[i][j][rem] = ans;
                }
            }
        }
        return dp[0][n - 1][k];
    }
};