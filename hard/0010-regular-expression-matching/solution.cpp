#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = s.length();
        int n = p.length();

        // Use a fixed-size array on the stack.
        // Constraints say length <= 20, so [21][21] is perfect and uses tiny memory.
        bool dp[21][21] = {false};

        // Base Case: Empty string matches empty pattern
        dp[0][0] = true;

        // Initialize 0th row: Patterns like a*, a*b*, c* that match empty string
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                // Look back 2 columns to skip the character and the star
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If current char matches or is a dot '.'
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                // If current char is a '*'
                else if (p[j - 1] == '*') {
                    // Option 1: Treat '*' as zero occurrences of the previous element.
                    // We look back 2 indices in the pattern.
                    dp[i][j] = dp[i][j - 2];

                    // Option 2: Treat '*' as one or more occurrences.
                    // We check if the previous char in pattern matches current char in string.
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        // If it matches, we can "consume" the string char (look up)
                        // OR keep the result from Option 1.
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};