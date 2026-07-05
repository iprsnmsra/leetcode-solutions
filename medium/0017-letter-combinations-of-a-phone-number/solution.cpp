#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void solve(int idx, string& digits, string& temp, vector<string>& ans, const vector<string>& mapping) {
        if (idx == digits.size()) {
            ans.push_back(temp);
            return;
        }

        int digit = digits[idx] - '0';
        string value = mapping[digit];

        for (int i = 0; i < value.length(); i++) {
            temp.push_back(value[i]);
            solve(idx + 1, digits, temp, ans, mapping);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) return ans;

        string temp = "";
        const vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(0, digits, temp, ans, mapping);
        return ans;
    }
};