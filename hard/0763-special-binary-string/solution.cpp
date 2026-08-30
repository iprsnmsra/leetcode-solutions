#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<string> blocks;
        int count = 0;
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                
                // Recursively maximize the inner string, then wrap it back up
                string maximized_block = "1" + makeLargestSpecial(inner) + "0";
                
                blocks.push_back(maximized_block);
                
                start = i + 1;
            }
        }
        sort(blocks.begin(), blocks.end(), greater<string>());

        // 4. Concatenate and return
        string result = "";
        for (const string& block : blocks) {
            result += block;
        }

        return result;
    }
};