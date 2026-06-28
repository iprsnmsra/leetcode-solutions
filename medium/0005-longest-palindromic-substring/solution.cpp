#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
       
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (s.empty()) return "";

        int start = 0;
        int maxLen = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {

            int len1 = expand(s, i, i, n);
            int len2 = expand(s, i, i + 1, n);

            int len = max(len1, len2);

            if (len > maxLen) {
                
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }

        return s.substr(start, maxLen);
    }

private:
   
    int expand(const string& s, int left, int right, int n) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return right - left - 1;
    }
};