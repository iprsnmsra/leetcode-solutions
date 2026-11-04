#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int max_val = 0;
        int total_sum = 0;

        // 1. Single O(N) L1 Cache Contiguous Forward Sweep
        // We extract both the global sum and the absolute ceiling simultaneously.
        for (int num : nums) {
            if (num > max_val) {
                max_val = num;
            }
            total_sum += num;
        }

        // 2. O(1) Algebraic Resolution
        // Total moves = (Count of elements * Target Maximum) - Current Sum of elements
        return (nums.size() * max_val) - total_sum;
    }
};