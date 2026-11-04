#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        
        // Phase 1: Precompute the minimum operation cost for every subarray of size x
        vector<long long> cost(n - x + 1);
        
        multiset<long long> left_set, right_set;
        long long left_sum = 0, right_sum = 0;
        
        // Helper lambda to strictly balance the sizes of the two median multisets
        auto balance = [&]() {
            while (left_set.size() > (x + 1) / 2) {
                auto it = prev(left_set.end());
                long long val = *it;
                right_set.insert(val);
                right_sum += val;
                left_sum -= val;
                left_set.erase(it);
            }
            while (left_set.size() < (x + 1) / 2 && !right_set.empty()) {
                auto it = right_set.begin();
                long long val = *it;
                left_set.insert(val);
                left_sum += val;
                right_sum -= val;
                right_set.erase(it);
            }
        };
        
        // Helper lambda to insert an incoming window element
        auto insert_val = [&](long long val) {
            if (left_set.empty() || val <= *left_set.rbegin()) {
                left_set.insert(val);
                left_sum += val;
            } else {
                right_set.insert(val);
                right_sum += val;
            }
            balance();
        };
        
        // Helper lambda to precisely erase an outgoing window element
        auto erase_val = [&](long long val) {
            if (!left_set.empty() && val <= *left_set.rbegin()) {
                left_set.erase(left_set.find(val));
                left_sum -= val;
            } else {
                right_set.erase(right_set.find(val));
                right_sum -= val;
            }
            balance();
        };
        
        // O(N log x) Sliding Sweep 
        for (int i = 0; i < n; ++i) {
            insert_val(nums[i]);
            
            // Retract the trailing element of the sliding window
            if (i >= x) {
                erase_val(nums[i - x]);
            }
            
            // Once the window establishes size 'x', calculate and snap the L1 Norm cost
            if (i >= x - 1) {
                long long median = *left_set.rbegin();
                long long current_cost = ((long long)left_set.size() * median - left_sum) + 
                                         (right_sum - (long long)right_set.size() * median);
                cost[i - x + 1] = current_cost;
            }
        }
        
        // Phase 2: Dynamic Programming Matrix 
        // dp[j][i] = min cost to pack j subarrays within the prefix nums[0 ... i-1]
        // Bounded to 1e18 to prevent long long integer overflows during summation
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 1e18));
        
        // Base Condition: 0 subarrays cost 0 operations regardless of prefix length
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = 0;
        }
        
        // O(K * N) Tabulation
        for (int j = 1; j <= k; ++j) {
            for (int i = j * x; i <= n; ++i) {
                // Option 1: Skip placing a subarray that ends at index (i-1)
                // Option 2: Place a subarray ending at index (i-1), chaining the previous (j-1) states
                dp[j][i] = min(dp[j][i - 1], dp[j - 1][i - x] + cost[i - x]);
            }
        }
        
        return dp[k][n];
    }
};