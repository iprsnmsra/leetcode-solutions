#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (text1.length() < text2.length()) {
            swap(text1, text2);
        }

        int m = text1.length();
        int n = text2.length();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= m; ++i) {

            int prev_diagonal = 0; 
            
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j]; 
                
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = prev_diagonal + 1;
                } else {

                    dp[j] = max(dp[j], dp[j - 1]);
                }

                prev_diagonal = temp; 
            }
        }
        return dp[n];
    }
};