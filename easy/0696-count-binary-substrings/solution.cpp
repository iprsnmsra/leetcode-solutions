#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int prev_len = 0;
        int curr_len = 1;
        int total_count = 0;
        int n = s.length();
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
              
                curr_len++;
            } else {
                total_count += min(prev_len, curr_len);
                
                
                prev_len = curr_len;
                
                curr_len = 1;
            }
        }
        total_count += min(prev_len, curr_len);

        return total_count;
    }
};