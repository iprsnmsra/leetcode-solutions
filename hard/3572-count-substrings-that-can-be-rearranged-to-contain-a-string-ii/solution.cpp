#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int req_count[26] = {0};
        int window_count[26] = {0};
        int missing_chars = 0;
        for (char c : word2) {
            if (req_count[c - 'a'] == 0) {
                missing_chars++;
            }
            req_count[c - 'a']++;
        }

        long long total_valid_substrings = 0;
        int left = 0;
        int n = word1.length();
        for (int right = 0; right < n; ++right) {
            int char_idx = word1[right] - 'a';
            window_count[char_idx]++;
            if (req_count[char_idx] > 0 && window_count[char_idx] == req_count[char_idx]) {
                missing_chars--;
            }
            while (missing_chars == 0) {
              
                total_valid_substrings += (n - right);

                int left_char_idx = word1[left] - 'a';
                window_count[left_char_idx]--;
                if (req_count[left_char_idx] > 0 && window_count[left_char_idx] < req_count[left_char_idx]) {
                    missing_chars++;
                }
                
                left++;
            }
        }

        return total_valid_substrings;
    }
};