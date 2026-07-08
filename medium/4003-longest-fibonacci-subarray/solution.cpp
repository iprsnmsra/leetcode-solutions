#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        if (n < 3) return n;

        int max_len = 2;
        int current_len = 2;

        for (int i = 2; i < n; ++i) {
            if ((long long)nums[i - 1] + nums[i - 2] == nums[i]) {
                current_len++;
                max_len = max(max_len, current_len);
            } else {
                current_len = 2;
            }
        }

        return max_len;
    }
};