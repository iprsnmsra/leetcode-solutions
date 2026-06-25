#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int furthest_reach = 0;
        int target = nums.size() - 1;

        for (int i = 0; i <= target; ++i) {

            if (i > furthest_reach) {
                return false;
            }

            furthest_reach = max(furthest_reach, i + nums[i]);
            if (furthest_reach >= target) {
                return true;
            }
        }

        return true;
    }
};