#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string maximumXor(string s, string t) {
  
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ones_t = 0;
        for (char c : t) {
            if (c == '1') {
                ones_t++;
            }
        }
        int zeros_t = t.length() - ones_t;
        string result = "";
        result.reserve(s.length());

        for (char c : s) {
            if (c == '0') {
                if (ones_t > 0) {
                    result += '1';
                    ones_t--;
                } else {
                    result += '0';
                    zeros_t--;
                }
            } else {
             
                if (zeros_t > 0) {
                    result += '1';
                    zeros_t--;
                } else {
                    result += '0';
                    ones_t--;
                }
            }
        }

        return result;
    }
};