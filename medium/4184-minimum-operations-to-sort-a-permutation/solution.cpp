#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Fast I/O execution
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();

        // 1. Check Type A: Forward Cyclic Shift R_k(S)
        int k_A = nums[0];
        bool is_type_A = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (k_A + i) % n) {
                is_type_A = false;
                break;
            }
        }

        if (is_type_A) {
            if (k_A == 0) return 0;
            return min(n - k_A, k_A + 2);
        }

        // 2. Check Type B: Reversed Cyclic Shift Rev(R_k(S))
        int k_B = (nums[0] + 1) % n;
        bool is_type_B = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (k_B - 1 - i + n) % n) {
                is_type_B = false;
                break;
            }
        }

        if (is_type_B) {
            return min(k_B + 1, n - k_B + 1);
        }

        // 3. Permutation is unreachable in D_N
        return -1;
    }
};