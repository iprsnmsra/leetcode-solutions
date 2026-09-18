#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = arr.size();
        
        // 1. Data Abstraction: 1D Temporal Cache
        // Initialized to 10^9 to aggressively prevent signed integer overflow
        // when mathematically evaluating `len + best_so_far[left - 1]`
        vector<int> best_so_far(n, 1e9); 
        
        int sum = 0;
        int left = 0;
        int min_total = 1e9;
        int current_best_len = 1e9;

        // 2. The L1 Cache Hardware Sweep
        for (int right = 0; right < n; ++right) {
            sum += arr[right];
            
            // Strictly monotonic window collapse
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }
            
            // 3. The Algebraic Sub-Array Resolution
            if (sum == target) {
                int len = right - left + 1;
                
                // If a valid historical interval exists entirely to our left, merge them
                if (left > 0 && best_so_far[left - 1] != 1e9) {
                    min_total = min(min_total, len + best_so_far[left - 1]);
                }
                // Register this interval as the new standard to beat
                current_best_len = min(current_best_len, len);
            }
            
            // 4. Cascade the optimal state forward synchronously
            best_so_far[right] = current_best_len;
        }

        return min_total >= 1e9 ? -1 : min_total;
    }
};