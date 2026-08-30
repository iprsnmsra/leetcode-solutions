#pragma GCC optimize("O3", "unroll-loops")
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int min_diff = 2e9; 
        vector<int> prev_ors;

        for (int num : nums) {
            vector<int> curr_ors;
            curr_ors.push_back(num);
            min_diff = min(min_diff, abs(k - num));

            for (int prev_or : prev_ors) {
                int new_or = prev_or | num;
                curr_ors.push_back(new_or);
                min_diff = min(min_diff, abs(k - new_or));
            }
            sort(curr_ors.begin(), curr_ors.end());
            curr_ors.erase(unique(curr_ors.begin(), curr_ors.end()), curr_ors.end());
            prev_ors = curr_ors;
        }

        return min_diff;
    }
};