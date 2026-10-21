#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums1.size();
        long long k = (long long)k1 + k2; // Combined operation budget

        // 1. Calculate absolute differences and find the max difference
        vector<long long> diff(n);
        long long total_diff_sum = 0;
        int max_val = 0;

        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total_diff_sum += diff[i];
            if (diff[i] > max_val) {
                max_val = diff[i];
            }
        }

        // 2. Early Exit: If total budget can eliminate all differences to 0
        if (total_diff_sum <= k) {
            return 0;
        }

        // 3. Frequency Bucket Array
        // Since max possible difference is 10^5, a fixed-size frequency table is O(max_val)
        vector<long long> count(max_val + 1, 0);
        for (int i = 0; i < n; ++i) {
            count[diff[i]]++;
        }

        // 4. Greedy Cascade from Top to Bottom
        for (int i = max_val; i > 0 && k > 0; --i) {
            if (count[i] == 0) continue;

            // Determine how many elements at level 'i' we can drop down to level 'i - 1'
            long long take = min(k, count[i]);
            
            count[i] -= take;
            count[i - 1] += take;
            k -= take;
        }

        // 5. Calculate Final Sum of Squared Differences
        long long ans = 0;
        for (int i = 1; i <= max_val; ++i) {
            if (count[i] > 0) {
                ans += count[i] * (long long)i * i;
            }
        }

        return ans;
    }
};