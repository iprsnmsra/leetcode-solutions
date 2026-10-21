#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    // Helper function to verify if a divisor k is sortable in O(n) time
    bool isSortable(const vector<int>& nums, int n, int k) {
        int prev_max = -1;

        for (int i = 0; i < n; i += k) {
            int drops = 0;
            int drop_idx = -1;

            // 1. Single-pass cyclic drop count evaluation
            for (int j = 0; j < k; ++j) {
                int curr = nums[i + j];
                int next = nums[i + (j + 1) % k];
                if (curr > next) {
                    drops++;
                    drop_idx = j;
                }
            }

            // More than 1 drop mathematically destroys cyclic sortability
            if (drops > 1) {
                return false;
            }

            // 2. Extract block bounds without physical rotation
            int block_min, block_max;
            if (drops == 0) {
                block_min = nums[i];
                block_max = nums[i + k - 1];
            } else { // drops == 1
                block_min = nums[i + (drop_idx + 1) % k];
                block_max = nums[i + drop_idx];
            }

            // 3. Verify non-decreasing order across block boundaries
            if (prev_max != -1 && block_min < prev_max) {
                return false;
            }
            prev_max = block_max;
        }

        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int sum_k = 0;

        // 1. Extract all divisors of n in O(sqrt(n)) time
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }

        // 2. Test each divisor against the invariant
        for (int k : divisors) {
            if (isSortable(nums, n, k)) {
                sum_k += k;
            }
        }

        return sum_k;
    }
};