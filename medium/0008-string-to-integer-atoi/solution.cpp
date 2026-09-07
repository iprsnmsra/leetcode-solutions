#include <string>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        // Optimization: Disable sync with C-style I/O for speed
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i = 0;
        int n = s.length();
        
        // 1. Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check for sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits
        long long result = 0; // Use long long to temporarily hold the value before clamping
        
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // Early Overflow Check
            // If result exceeds the threshold where *10 would overflow INT_MAX
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return (int)(result * sign);
    }
};