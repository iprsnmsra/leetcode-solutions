#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int k = (n + 1) / 2;
        if (k < n) {
            nth_element(nums.begin(), nums.begin() + k, nums.end(), 
                [](int a, int b) {
                    return abs(a) > abs(b);
                }
            );
        }

        long long max_score = 0;
        for (int i = 0; i < k; ++i) {
            max_score += (long long)nums[i] * nums[i];
        }
        for (int i = k; i < n; ++i) {
            max_score -= (long long)nums[i] * nums[i];
        }

        return max_score;
    }
};