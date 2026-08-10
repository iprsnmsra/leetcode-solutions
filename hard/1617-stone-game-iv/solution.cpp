class Solution {
public:
    bool winnerSquareGame(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<char> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                if (dp[i - k * k] == 0) {
                    dp[i] = 1;
                    break; 
                }
            }
        }
        return dp[n] == 1;
    }
};