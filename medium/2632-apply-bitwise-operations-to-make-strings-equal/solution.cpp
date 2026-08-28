#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        bool s_has_one = (s.find('1') != string::npos);
        bool target_has_one = (target.find('1') != string::npos);
        return s_has_one == target_has_one;
    }
};