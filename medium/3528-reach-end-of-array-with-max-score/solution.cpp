#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long max_score = 0;
        int current_max = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            current_max = max(current_max, nums[i]);
            max_score += current_max;
        }

        return max_score;
    }
};