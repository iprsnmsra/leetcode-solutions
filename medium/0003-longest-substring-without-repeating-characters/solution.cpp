#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> dict(256, -1);
        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]] > -1) {
                start = max(start, dict[s[i]] + 1);
            }
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};