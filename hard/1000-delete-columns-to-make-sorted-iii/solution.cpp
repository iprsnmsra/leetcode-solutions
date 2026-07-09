#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (strs.empty()) return 0;
        
        int n = strs.size();
        int m = strs[0].length();

        vector<int> dp(m, 1);
        int max_kept = 1;

        for (int j = 1; j < m; ++j) {

            for (int i = 0; i < j; ++i) {
                bool valid = true;

                for (int row = 0; row < n; ++row) {
                    if (strs[row][i] > strs[row][j]) {
                        valid = false;
                        break; 
                    }
                }

                if (valid) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            max_kept = max(max_kept, dp[j]);
        }

        return m - max_kept;
    }
};