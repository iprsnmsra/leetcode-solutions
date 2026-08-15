#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int neg_count = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos_start = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        int pos_count = nums.size() - pos_start;

        return max(neg_count, pos_count);
    }
};