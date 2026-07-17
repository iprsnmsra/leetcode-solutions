#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (s.length() != goal.length()) {
            return false;
        }
        string doubled = s + s;

        return doubled.find(goal) != string::npos;
    }
};