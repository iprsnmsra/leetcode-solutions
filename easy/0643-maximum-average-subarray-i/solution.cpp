#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int current_sum = 0;
        int max_sum = 0;
        for (int i = 0; i < k; ++i) {
            current_sum += nums[i];
        }
        max_sum = current_sum;
        for (int i = k; i < n; ++i) {
            current_sum += nums[i] - nums[i - k];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
        return (double)max_sum / k;
    }
};