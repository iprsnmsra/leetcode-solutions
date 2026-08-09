#include <vector>
#include <numeric> // For std::accumulate
#include <iostream>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        int left_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int right_sum = total_sum - left_sum - nums[i];
            if (left_sum == right_sum) {
                return i;
            }
            left_sum += nums[i];
        }

        return -1;
    }
};