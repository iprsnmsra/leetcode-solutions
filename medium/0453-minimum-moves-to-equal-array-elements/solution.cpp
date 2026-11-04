#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long total_sum = 0;
        int min_val = nums[0];

        // 1. Single O(N) L1 Cache Contiguous Forward Sweep
        // We extract both the global sum and global minimum simultaneously.
        for (int num : nums) {
            total_sum += num;
            if (num < min_val) {
                min_val = num;
            }
        }

        // 2. O(1) Mathematical Resolution
        // Total moves = Sum(nums) - (N * min_val)
        long long moves = total_sum - (long long)min_val * nums.size();

        return (int)moves;
    }
};