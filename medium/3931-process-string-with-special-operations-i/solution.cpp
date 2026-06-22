#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string processStr(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string result;
        result.reserve(1024);

        for (char c : s) {
            if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } 
            else if (c == '#') {
                result += result;
            } 
            else if (c == '%') {
                reverse(result.begin(), result.end());
            } 
            else {
                result.push_back(c);
            }
        }

        return result;
    }
};