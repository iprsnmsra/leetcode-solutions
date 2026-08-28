#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }

        int best_k = -1;
        char best_c = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (freq[c] > 0) {
                    best_k = i;
                    best_c = c + 'a';
                    break;
                }
            }

            if (freq[target[i] - 'a'] > 0) {
                freq[target[i] - 'a']--;
            } else {
                break;
            }
        }

        if (best_k == -1) return "";
        int final_freq[26] = {0};
        for (char c : s) final_freq[c - 'a']++;

        string ans = "";
        ans.reserve(s.length());
        for (int i = 0; i < best_k; ++i) {
            ans += target[i];
            final_freq[target[i] - 'a']--;
        }
        ans += best_c;
        final_freq[best_c - 'a']--;
        for (int i = 0; i < 26; ++i) {
            if (final_freq[i] > 0) {
                ans.append(final_freq[i], i + 'a');
            }
        }

        return ans;
    }
};