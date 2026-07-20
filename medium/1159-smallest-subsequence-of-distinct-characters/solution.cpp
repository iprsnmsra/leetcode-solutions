#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> last_occurrence(26, 0);
        vector<bool> in_stack(26, false);
        for (int i = 0; i < s.length(); ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }
        string result = ""; 
        for (int i = 0; i < s.length(); ++i) {
            char curr = s[i];
            if (in_stack[curr - 'a']) continue;
            while (!result.empty() && result.back() > curr && last_occurrence[result.back() - 'a'] > i) {
                in_stack[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(curr);
            in_stack[curr - 'a'] = true;
        }

        return result;
    }
};