#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (k <= 1) return 0;
        

        sort(nums.begin(), nums.end());
        
        int min_diff = INT_MAX;

        for (int i = 0; i <= nums.size() - k; ++i) {
            int current_diff = nums[i + k - 1] - nums[i];

            if (current_diff < min_diff) {
                min_diff = current_diff;
            }
        }
        
        return min_diff;
    }
};