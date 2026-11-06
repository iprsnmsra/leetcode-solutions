#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        // Optimization: Fast I/O execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Initialize with all bits set to 1 (-1 in two's complement representation)
        int bitwise_mask = -1;
        int n = nums.size();
        
        // Single O(N) L1 Cache Contiguous Forward Sweep
        for (int i = 0; i < n; ++i) {
            // Isolate strictly misplaced elements requiring displacement
            if (nums[i] != i) {
                bitwise_mask &= nums[i];
            }
        }

        // If no elements were misplaced, bitwise_mask remains -1; max(bitwise_mask, 0) defaults k to 0
        return max(bitwise_mask, 0);
    }
};