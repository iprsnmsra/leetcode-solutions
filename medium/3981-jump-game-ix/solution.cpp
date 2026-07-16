#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        if (n == 0) return {};

        vector<int> max_left(n);
        max_left[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            max_left[i] = max(max_left[i - 1], nums[i]);
        }

        vector<int> min_right(n);
        min_right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_right[i] = min(min_right[i + 1], nums[i]);
        }

        vector<int> ans(n);
        int start = 0;

        for (int i = 0; i < n; ++i) {

            if (i == n - 1 || max_left[i] <= min_right[i + 1]) {
                int block_max = 0;
                for (int j = start; j <= i; ++j) {
                    block_max = max(block_max, nums[j]);
                }

                for (int j = start; j <= i; ++j) {
                    ans[j] = block_max;
                }

                start = i + 1; 
            }
        }

        return ans;
    }
};