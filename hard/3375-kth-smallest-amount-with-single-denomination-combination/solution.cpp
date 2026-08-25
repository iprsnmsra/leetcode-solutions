#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
    long long lcm(long long a, long long b, long long limit) {
        if (a == 0 || b == 0) return 0;
        long long g = gcd(a, b);
        if (limit / (b / g) < a) return limit + 1; 
        return a * (b / g);
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = coins.size();
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long MAX_LIMIT = min_coin * k; 
        vector<pair<long long, int>> pie_subsets;
        pie_subsets.reserve(1 << n);
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    current_lcm = lcm(current_lcm, coins[i], MAX_LIMIT);
                    if (current_lcm > MAX_LIMIT) break; 
                }
            }
            
            if (current_lcm <= MAX_LIMIT) {
                int sign = (__builtin_popcount(mask) % 2 == 1) ? 1 : -1;
                pie_subsets.push_back({current_lcm, sign});
            }
        }
        long long left = 1;
        long long right = MAX_LIMIT;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long current_count = 0;
            for (const auto& subset : pie_subsets) {
                current_count += (mid / subset.first) * subset.second;
            }

            if (current_count >= k) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};