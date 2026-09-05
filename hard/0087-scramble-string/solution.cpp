#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {

    int memo[31][30][30];
    string S1, S2;

public:
    bool isScramble(string s1, string s2) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;

        S1 = s1;
        S2 = s2;
        int n = s1.length();

       
        memset(memo, 0, sizeof(memo));

        return solve(0, 0, n);
    }

private:
    bool solve(int i, int j, int len) {
        // Base Case 1: Single character
        if (len == 1) {
            return S1[i] == S2[j];
        }

        // Check Memoization
        if (memo[len][i][j] != 0) {
            return memo[len][i][j] == 1;
        }


        bool res = false;

        for (int k = 1; k < len; ++k) {
            // Case 1: No Swap
            // S1_left -> S2_left  AND  S1_right -> S2_right
            if (solve(i, j, k) && solve(i + k, j + k, len - k)) {
                res = true;
                break;
            }
            if (solve(i, j + len - k, k) && solve(i + k, j, len - k)) {
                res = true;
                break;
            }
        }

        // Store result (1 for true, 2 for false)
        memo[len][i][j] = res ? 1 : 2;
        return res;
    }
};