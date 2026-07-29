#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        bool seen_digit = false;
        bool seen_exponent = false;
        bool seen_dot = false;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (c >= '0' && c <= '9') {
                seen_digit = true;
            } 
            else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (c == 'e' || c == 'E') {
                if (seen_exponent || !seen_digit) {
                    return false;
                }
                seen_exponent = true;
                seen_digit = false; 
            } 
            else if (c == '.') {
                if (seen_dot || seen_exponent) {
                    return false;
                }
                seen_dot = true;
            } 
            else {
                return false;
            }
        }
        return seen_digit;
    }
};