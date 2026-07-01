#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int k = n - 2;

        while (k >= 0 && nums[k] >= nums[k + 1]) {
            k--;
        }

        if (k >= 0) {
     
            int l = n - 1;
            while (l > k && nums[l] <= nums[k]) {
                l--;
            }

            swap(nums[k], nums[l]);
        }

        reverse(nums.begin() + k + 1, nums.end());
    }
};