#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;

        int half_freq[26] = {0};
        int odd_count = 0;
        char center_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                odd_count++;
                center_char = i + 'a';
            }
            half_freq[i] = freq[i] / 2;
        }
        if (odd_count > 1) return "";

        int half_len = n / 2;
        string target_L = target.substr(0, half_len);
        bool can_match_exact = true;
        int temp_freq[26];
        copy(begin(half_freq), end(half_freq), begin(temp_freq));

        for (char c : target_L) {
            if (temp_freq[c - 'a'] > 0) {
                temp_freq[c - 'a']--;
            } else {
                can_match_exact = false;
                break;
            }
        }

        if (can_match_exact) {
            string p_exact = target_L;
            if (odd_count == 1) p_exact += center_char;
            
            string R = target_L;
            reverse(R.begin(), R.end());
            p_exact += R;
            if (p_exact > target) {
                return p_exact;
            }
        }
        int best_k = -1;
        char best_c = 0;
        copy(begin(half_freq), end(half_freq), begin(temp_freq));

        for (int i = 0; i < half_len; ++i) {
            for (int c = target_L[i] - 'a' + 1; c < 26; ++c) {
                if (temp_freq[c] > 0) {
                    best_k = i;
                    best_c = c + 'a';
                    break;
                }
            }
            if (temp_freq[target_L[i] - 'a'] > 0) {
                temp_freq[target_L[i] - 'a']--;
            } else {
                break;
            }
        }

        if (best_k == -1) return "";
        string L = "";
        L.reserve(half_len); 
        
        int final_freq[26];
        copy(begin(half_freq), end(half_freq), begin(final_freq));
        for (int i = 0; i < best_k; ++i) {
            L += target_L[i];
            final_freq[target_L[i] - 'a']--;
        }
        L += best_c;
        final_freq[best_c - 'a']--;
        for (int i = 0; i < 26; ++i) {
            if (final_freq[i] > 0) {
                L.append(final_freq[i], i + 'a');
            }
        }

 
        string R = L;
        reverse(R.begin(), R.end());

        string ans = L;
        if (odd_count == 1) ans += center_char;
        ans += R;

        return ans;
    }
};