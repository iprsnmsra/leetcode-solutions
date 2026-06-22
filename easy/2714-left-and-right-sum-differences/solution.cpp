#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        int left_sum = 0;
        int n = nums.size();
        vector<int> answer(n);

        for (int i = 0; i < n; ++i) {
            int right_sum = total_sum - left_sum - nums[i];

            answer[i] = abs(left_sum - right_sum);

            left_sum += nums[i];
        }

        return answer;
    }
};