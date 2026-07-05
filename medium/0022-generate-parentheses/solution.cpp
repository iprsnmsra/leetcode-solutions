#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  
    void solve(int open, int close, int n, string& s, vector<string>& ans) {
       
        if (s.length() == n * 2) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');
            solve(open + 1, close, n, s, ans);
            s.pop_back(); 
        }

        if (close < open) {
            s.push_back(')');
            solve(open, close + 1, n, s, ans);
            s.pop_back(); 
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        s.reserve(n * 2); 
        solve(0, 0, n, s, ans);
        return ans;
    }
};