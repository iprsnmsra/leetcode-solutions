#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int count_less = 0;
        int count_equal = 0;

        // 1. Single O(N) L1 Cache Contiguous Forward Sweep
        // We bypass O(N log N) sorting entirely by tracking scalar element ranks.
        for (int num : nums) {
            if (num < target) {
                count_less++;
            } else if (num == target) {
                count_equal++;
            }
        }

        // 2. Exact Memory Pre-allocation
        // Prevents dynamic heap reallocation during result vector population
        vector<int> result;
        result.reserve(count_equal);

        // 3. Direct Index Generation
        for (int i = 0; i < count_equal; ++i) {
            result.push_back(count_less + i);
        }

        return result;
    }
};