#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i = 0; 
        int j = 0; 

        int s_len = s.length();
        int t_len = t.length();
        while (i < s_len && j < t_len) {
            if (s[i] == t[j]) {
                i++; 
            }
            j++;
        }
        return i == s_len;
    }
};