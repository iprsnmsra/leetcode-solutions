#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (word1.length() < word2.length()) {
            swap(word1, word2);
        }

        int m = word1.length();
        int n = word2.length();

        vector<int> dp(n + 1, 0);

        for (int j = 0; j <= n; ++j) {
            dp[j] = j; 
        }

        for (int i = 1; i <= m; ++i) {
            int prev_diagonal = dp[0];
            dp[0] = i; 

            for (int j = 1; j <= n; ++j) {
                int temp = dp[j]; 

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev_diagonal;
                } else {

                    dp[j] = min({dp[j - 1], dp[j], prev_diagonal}) + 1;
                }
                prev_diagonal = temp; 
            }
        }

        return dp[n];
    }
};