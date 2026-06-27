#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int prev2 = 0;
        int prev1 = 0;

        for (int i = 0; i < nums.size(); ++i) {

            int current_max = max(prev2 + nums[i], prev1);

            prev2 = prev1;
            prev1 = current_max;
        }
        return prev1;
    }
};