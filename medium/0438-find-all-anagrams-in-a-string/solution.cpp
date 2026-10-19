#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        int m = p.length();
        if (n < m) return {};

        vector<int> res;
        int count[26] = {0};
        for (int i = 0; i < m; ++i) {
            count[p[i] - 'a']--;
            count[s[i] - 'a']++; 
        }
        int diff_count = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                diff_count++;
            }
        }

        if (diff_count == 0) {
            res.push_back(0);
        }
        for (int i = m; i < n; ++i) {
            int right_char = s[i] - 'a';
            int left_char = s[i - m] - 'a';
            count[right_char]++;
            if (count[right_char] == 1) diff_count++;      
            else if (count[right_char] == 0) diff_count--; 
            count[left_char]--;
            if (count[left_char] == -1) diff_count++;    
            else if (count[left_char] == 0) diff_count--; 
            if (diff_count == 0) {
                res.push_back(i - m + 1);
            }
        }

        return res;
    }
};