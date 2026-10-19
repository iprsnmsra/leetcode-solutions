#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int total_sum = 0;

        // 1. Incremental Left Endpoint Sweep
        for (int i = 0; i < n; ++i) {
            // 2. Stack-Allocated L1 Bitset (Zero Heap Mallocs)
            // Bounded to 101 bits since nums[i] <= 100
            bitset<101> seen;
            int distinct_count = 0;

            // 3. Incremental Right Endpoint Expansion
            for (int j = i; j < n; ++j) {
                int val = nums[j];
                
                // Hardware bit lookup: Check and update in single clock cycle
                if (!seen[val]) {
                    seen[val] = true;
                    distinct_count++;
                }
                
                // Accumulate square of distinct count
                total_sum += distinct_count * distinct_count;
            }
        }

        return total_sum;
    }
};