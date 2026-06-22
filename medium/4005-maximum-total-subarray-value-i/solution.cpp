#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int global_min = nums[0];
        int global_max = nums[0];

        for (int num : nums) {
            if (num < global_min) global_min = num;
            if (num > global_max) global_max = num;
        }

        long long best_subarray_value = global_max - global_min;
        return (long long)k * best_subarray_value;
    }
};