#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        int required_count = 1 << k; 
        if (n - k + 1 < required_count) {
            return false;
        }
        vector<bool> seen(required_count, false);
        
        int mask = required_count - 1; 
        int current_val = 0;
        for (int i = 0; i < k - 1; ++i) {
            current_val = (current_val << 1) | (s[i] - '0');
        }
        for (int i = k - 1; i < n; ++i) {
           
            current_val = ((current_val << 1) & mask) | (s[i] - '0');
            if (!seen[current_val]) {
                seen[current_val] = true;
                required_count--;
                if (required_count == 0) {
                    return true;
                }
            }
        }

        return false;
    }
};