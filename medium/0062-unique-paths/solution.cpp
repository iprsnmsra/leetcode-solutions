class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int total_steps = m + n - 2;

        int k = min(m - 1, n - 1);
        for (int i = 1; i <= k; ++i) {
            ans = ans * (total_steps - i + 1) / i;
        }
        
        return ans;
    }
};