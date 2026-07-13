#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();

        vector<int> dp(n, -1);
        dp[0] = 0; 

        for (int i = 0; i < n; ++i) {

            if (dp[i] == -1) continue;

            for (int j = i + 1; j < n; ++j) {
                if (abs((long long)nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        
        return dp[n - 1];
    }
};