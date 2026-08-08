#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string ans = "";
        for (char c : s) {
            if (c == '*') {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};