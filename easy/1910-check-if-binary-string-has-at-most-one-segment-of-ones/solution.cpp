#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '0' && s[i + 1] == '1') {
                return false;
            }
        }
        return true;
    }
};