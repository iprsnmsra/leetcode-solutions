#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> freq(n + 1, 0);
        for (const auto& req : requests) {
            freq[req[0]]++;
            freq[req[1] + 1]--;
        }
        for (int i = 1; i < n; ++i) {
            freq[i] += freq[i - 1];
        }
        freq.pop_back();
        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());

        long long max_total = 0;
        const int MOD = 1e9 + 7;
        for (int i = n - 1; i >= 0; --i) {
            if (freq[i] == 0) break;
            long long contribution = (long long)nums[i] * freq[i];
            max_total = (max_total + contribution) % MOD;
        }

        return max_total;
    }
};