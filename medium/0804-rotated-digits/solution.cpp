#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> dp(n + 1, 0);
        int count = 0;

        for (int i = 0; i <= n; ++i) {
            if (i < 10) {

                if (i == 0 || i == 1 || i == 8) {
                    dp[i] = 1;
                } else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                    count++;
                }
            } else {

                int prefix_state = dp[i / 10];
                int suffix_state = dp[i % 10];

                if (prefix_state == 1 && suffix_state == 1) {

                    dp[i] = 1;
                } else if (prefix_state >= 1 && suffix_state >= 1) {

                    dp[i] = 2;
                    count++;
                }
            }
        }

        return count;
    }
};