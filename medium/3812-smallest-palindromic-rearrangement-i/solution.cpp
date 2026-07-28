#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string left_half = "";
        char middle_char = 0; 
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                middle_char = 'a' + i;
            }
            left_half.append(count[i] / 2, 'a' + i);
        }
        string result = left_half;
        
        if (middle_char != 0) {
            result += middle_char;
        }
        reverse(left_half.begin(), left_half.end());
        result += left_half;

        return result;
    }
};