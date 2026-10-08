#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int write_idx = 0;
        int depth = 0;

        // 1. The L1 Cache Contiguous Forward Sweep
        for (char c : s) {
            // 2. Hardware-Level Post-Increment & Pre-Decrement Evaluation
            // If condition passes, destructively overwrite the physical memory block in-place
            if (c == '(' && depth++ > 0) {
                s[write_idx++] = c;
            }
            if (c == ')' && --depth > 0) {
                s[write_idx++] = c;
            }
        }

        // 3. Absolute Memory Re-utilization
        // Truncate the string to the exact boundary of the write head, 
        // completely bypassing the OS memory allocator.
        s.resize(write_idx);
        
        return s;
    }
};