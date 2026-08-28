#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int sum1 = 0, sum2 = 0;
        int curr_gain1 = 0, max_gain1 = 0;
        int curr_gain2 = 0, max_gain2 = 0;

        int n = nums1.size();

        for (int i = 0; i < n; ++i) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            int diff1 = nums2[i] - nums1[i];
            curr_gain1 = max(0, curr_gain1 + diff1);
            max_gain1 = max(max_gain1, curr_gain1);
            int diff2 = nums1[i] - nums2[i];
            curr_gain2 = max(0, curr_gain2 + diff2);
            max_gain2 = max(max_gain2, curr_gain2);
        }
        return max(sum1 + max_gain1, sum2 + max_gain2);
    }
};