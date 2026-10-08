#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    void removeInvalid(string s, int last_i, int last_j, const vector<char>& par, vector<string>& res) {
        int stack_count = 0;
        for (int i = last_i; i < s.length(); ++i) {
            if (s[i] == par[0]) stack_count++;
            if (s[i] == par[1]) stack_count--;
            
            if (stack_count >= 0) continue; 
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == par[1] && (j == last_j || s[j - 1] != par[1])) {
                    removeInvalid(s.substr(0, j) + s.substr(j + 1), i, j, par, res);
                }
            }
            return; 
        }
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());
        
        if (par[0] == '(') {
            removeInvalid(reversed_s, 0, 0, {')', '('}, res);
        } else {
            res.push_back(reversed_s);
        }
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<string> res;
        removeInvalid(s, 0, 0, {'(', ')'}, res);
        return res;
    }
};