#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int l = 0;

        while (l + 1 < n && nums[l] < nums[l + 1]) {
            l++;
        }

        if (l == n - 1) {
            return (n * (n + 1)) / 2;
        }
        
        int r = n - 1;

        while (r > 0 && nums[r - 1] < nums[r]) {
            r--;
        }
        
        int count = n - r + 1;

        int j = r;
        for (int i = 0; i <= l; i++) {

            while (j < n && nums[i] >= nums[j]) {
                j++;
            }

            count += (n - j + 1);
        }
        
        return count;
    }
};