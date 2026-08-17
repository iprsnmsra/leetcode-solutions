#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int current_chain = nums[0];
        int global_max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            current_chain = max(nums[i], current_chain + nums[i]);
            if (current_chain > global_max) {
                global_max = current_chain;
            }
        }

        return global_max;
    }
};