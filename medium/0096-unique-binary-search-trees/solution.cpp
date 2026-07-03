class Solution {
public:
    int numTrees(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> dp(n + 1, 0);
        dp[0] = 1; 
        dp[1] = 1;
        for (int nodes = 2; nodes <= n; ++nodes) {
            for (int root = 1; root <= nodes; ++root) {
                
                int left_nodes = root - 1;
                int right_nodes = nodes - root;
                dp[nodes] += dp[left_nodes] * dp[right_nodes];
            }
        }

        return dp[n];
    }
};