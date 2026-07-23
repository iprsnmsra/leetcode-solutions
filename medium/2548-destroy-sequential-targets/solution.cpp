#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int, int> remainder_counts;
        int max_targets = 0;

        for (int num : nums) {
            int rem = num % space;
            remainder_counts[rem]++;

            if (remainder_counts[rem] > max_targets) {
                max_targets = remainder_counts[rem];
            }
        }

        int best_seed = INT_MAX;
        for (int num : nums) {
            int rem = num % space;
            if (remainder_counts[rem] == max_targets) {
                if (num < best_seed) {
                    best_seed = num;
                }
            }
        }

        return best_seed;
    }
};