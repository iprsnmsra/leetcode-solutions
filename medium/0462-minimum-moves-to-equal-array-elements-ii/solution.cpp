#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int mid = n / 2;

        // 1. O(N) In-Place Branchless Partitioning
        // Segregates the array based on the median without sorting the halves.
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        
        // The median is now guaranteed to reside exactly at the 'mid' index
        int median = nums[mid];
        
        int total_moves = 0;

        // 2. Hardware ALU Accumulation (L1 Norm)
        // Sweep contiguously to calculate the sum of absolute differences
        for (int num : nums) {
            total_moves += abs(num - median);
        }

        return total_moves;
    }
};