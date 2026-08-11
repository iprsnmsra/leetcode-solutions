#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        bool evens_match = (s1[0] == s2[0] && s1[2] == s2[2]) || 
                           (s1[0] == s2[2] && s1[2] == s2[0]);
        bool odds_match = (s1[1] == s2[1] && s1[3] == s2[3]) || 
                          (s1[1] == s2[3] && s1[3] == s2[1]);

        return evens_match && odds_match;
    }
};