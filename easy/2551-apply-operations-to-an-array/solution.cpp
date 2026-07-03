#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int write_idx = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                if (i < n - 1 && nums[i] == nums[i + 1]) {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
                swap(nums[write_idx], nums[i]);
                write_idx++;
            }
        }

        return nums;
    }
};