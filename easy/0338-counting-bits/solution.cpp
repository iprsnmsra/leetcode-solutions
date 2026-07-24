#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i >> 1] + (i & 1);
            
        }

        return dp;
    }
};