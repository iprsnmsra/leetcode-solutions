#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (needle.empty()) return 0;
        
        int n = haystack.length();
        int m = needle.length();
        
        if (m > n) return -1;
        for (int i = 0; i <= n - m; ++i) {
            if (haystack[i] == needle[0] && haystack[i + m - 1] == needle[m - 1]) {

                bool match = true;
                for (int j = 0; j < m; ++j) {
                    if (haystack[i + j] != needle[j]) {
                        match = false;
                        break;
                    }
                }
                
                if (match) return i;
            }
        }

        return -1;
    }
};