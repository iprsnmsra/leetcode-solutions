#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();

        if (s[n - 1] == '1') return false;

        vector<bool> dp(n, false);
        dp[0] = true;

        int active_launchpads = 0;

        for (int i = 1; i < n; ++i) {

            if (i >= minJump && dp[i - minJump]) {
                active_launchpads++;
            }

            if (i > maxJump && dp[i - maxJump - 1]) {
                active_launchpads--;
            }

            if (s[i] == '0' && active_launchpads > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};