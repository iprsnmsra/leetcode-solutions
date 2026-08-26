#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int score_diff = 0;
        bool is_p1_active = true;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 != 0) {
                is_p1_active = !is_p1_active;
            }
            if (i % 6 == 5) {
                is_p1_active = !is_p1_active;
            }
            if (is_p1_active) {
                score_diff += nums[i];
            } else {
                score_diff -= nums[i];
            }
        }

        return score_diff;
    }
};