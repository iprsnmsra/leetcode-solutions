#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        int write = 0;
        int read = 0;

        while (read < n) {
            while (read < n && s[read] == ' ') {
                read++;
            }
            if (read == n) break; 
            if (write > 0) {
                s[write++] = ' ';
            }

            int word_start = write;
            while (read < n && s[read] != ' ') {
                s[write++] = s[read++];
            }
            reverse(s.begin() + word_start, s.begin() + write);
        }
        s.resize(write);
        reverse(s.begin(), s.end());

        return s;
    }
};