#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        char rogue_char = 0;
        for (char c : s) {
            rogue_char ^= c;
        }
        for (char c : t) {
            rogue_char ^= c;
        }
        return rogue_char;
    }
};