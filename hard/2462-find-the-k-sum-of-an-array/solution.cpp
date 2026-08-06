#include <vector>
#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long max_sum = 0;
        for (int& num : nums) {
            if (num > 0) {
                max_sum += num;
            }
            num = abs(num);
        }

        sort(nums.begin(), nums.end());

        if (k == 1) return max_sum;
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> min_heap;
        
        min_heap.push({nums[0], 0});
        long long current_penalty = 0;
        for (int i = 1; i < k; ++i) {
            auto [penalty, idx] = min_heap.top();
            min_heap.pop();
            current_penalty = penalty;

            if (idx + 1 < nums.size()) {
                min_heap.push({penalty + nums[idx + 1], idx + 1});
                min_heap.push({penalty - nums[idx] + nums[idx + 1], idx + 1});
            }
        }
        return max_sum - current_penalty;
    }
};