#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int current_depth = 0;
        int max_depth = 0;

        // 1. L1 Cache Contiguous Forward Sweep
        for (char c : s) {
            // 2. Hardware Register Arithmetic (Zero Heap Allocation)
            if (c == '(') {
                current_depth++;
                // 3. Branch Prediction Locality
                // By nesting the max check inside the '(' branch, we avoid evaluating 
                // the max condition on the other 90% of irrelevant characters in the string.
                if (current_depth > max_depth) {
                    max_depth = current_depth;
                }
            } else if (c == ')') {
                current_depth--;
            }
        }

        return max_depth;
    }
};