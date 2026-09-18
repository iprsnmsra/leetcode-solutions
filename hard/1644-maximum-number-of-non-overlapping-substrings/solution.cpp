#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        
        // 1. O(1) Memory State: 52-Byte Hardware Registers
        int L[26];
        int R[26];
        fill(L, L + 26, 1e9);
        fill(R, R + 26, -1);

        // O(N) Spatial Boundary Mapping
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (L[c] == 1e9) L[c] = i;
            R[c] = i;
        }

        struct Interval { int start, end; };
        vector<Interval> valid_intervals;
        valid_intervals.reserve(26);

        // 2. The 26-State Expansion Sweep
        for (int i = 0; i < 26; ++i) {
            if (R[i] == -1) continue; // Character does not exist
            
            int right_bound = R[i];
            bool is_valid = true;
            
            // Expand boundary to encompass nested characters
            for (int j = L[i]; j <= right_bound; ++j) {
                int c = s[j] - 'a';
                if (L[c] < L[i]) {
                    is_valid = false;
                    break;
                }
                
                // Expand right boundary if nested character ends later
                right_bound = max(right_bound, R[c]);
            }
            
            if (is_valid) {
                valid_intervals.push_back({L[i], right_bound});
            }
        }
        sort(valid_intervals.begin(), valid_intervals.end(), [](const Interval& a, const Interval& b) {
            return a.end < b.end;
        });
        vector<string> result;
        int last_end = -1;
        
        for (const auto& interval : valid_intervals) {
            if (interval.start > last_end) {
                result.push_back(s.substr(interval.start, interval.end - interval.start + 1));
                last_end = interval.end;
            }
        }

        return result;
    }
};