#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (word1.length() != word2.length()) {
            return false;
        }
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (char c : word1) freq1[c - 'a']++;
        for (char c : word2) freq2[c - 'a']++;
        for (int i = 0; i < 26; ++i) {
            if ((freq1[i] == 0 && freq2[i] > 0) || (freq1[i] > 0 && freq2[i] == 0)) {
                return false;
            }
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2;
    }
};