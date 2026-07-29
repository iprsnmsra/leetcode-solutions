#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
    int memo[301][27];
    int getDist(int from, int to) {
      
        if (from == 26) return 0;
        
        int row1 = from / 6, col1 = from % 6;
        int row2 = to / 6, col2 = to % 6;
        
        return abs(row1 - row2) + abs(col1 - col2);
    }

    int dp(const string& word, int idx, int other_finger) {
        if (idx == word.length()) {
            return 0;
        }
        if (memo[idx][other_finger] != -1) {
            return memo[idx][other_finger];
        }

        int target = word[idx] - 'A';
        int prev_finger = (idx == 0) ? 26 : (word[idx - 1] - 'A');
        int cost1 = getDist(prev_finger, target) + dp(word, idx + 1, other_finger);
        int cost2 = getDist(other_finger, target) + dp(word, idx + 1, prev_finger);
        return memo[idx][other_finger] = min(cost1, cost2);
    }

public:
    int minimumDistance(string word) {
        for (int i = 0; i <= word.length(); ++i) {
            for (int j = 0; j < 27; ++j) {
                memo[i][j] = -1;
            }
        }
        return dp(word, 0, 26);
    }
};