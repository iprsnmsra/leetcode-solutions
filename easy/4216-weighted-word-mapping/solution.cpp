#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string ans = "";

        ans.reserve(words.size());

        for (const string& word : words) {
            int sum = 0;

            for (char c : word) {
                sum += weights[c - 'a'];
            }

            int val = sum % 26;

            ans += (char)('z' - val);
        }

        return ans;
    }
};