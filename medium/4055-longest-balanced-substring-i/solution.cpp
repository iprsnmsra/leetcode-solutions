#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // Renamed from 'longestBalancedSubstring' to 'longestBalanced' to match the judge
    int longestBalanced(string s) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        int max_len = 0;

        // Iterate over all possible start points
        for (int i = 0; i < n; ++i) {
            // Frequency array for current substring window
            // Since we process lowercase English letters, size 26 is enough.
            int counts[26] = {0};
            int distinct_count = 0;
            int max_freq = 0;

            // Iterate over all possible end points
            for (int j = i; j < n; ++j) {
                int char_idx = s[j] - 'a';

                // If this is the first time we see this char in the current window
                if (counts[char_idx] == 0) {
                    distinct_count++;
                }

                // Increment frequency
                counts[char_idx]++;
                
                // Update the maximum frequency seen in this window
                max_freq = max(max_freq, counts[char_idx]);

                // Current length of the substring
                int current_len = j - i + 1;

                // Check Balance Condition:
                // If every distinct character appears 'max_freq' times,
                // then total length MUST equal distinct_count * max_freq.
                if (max_freq * distinct_count == current_len) {
                    max_len = max(max_len, current_len);
                }
            }
        }

        return max_len;
    }
};