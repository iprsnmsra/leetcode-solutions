#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long MOD = 1e9 + 7;
        int bit_counts[32] = {0};
        for (int num : nums) {
            for (int bit = 0; bit < 31; ++bit) {
                if ((num >> bit) & 1) {
                    bit_counts[bit]++;
                }
            }
        }

        long long max_sum_squares = 0;
        for (int i = 0; i < k; ++i) {
            long long current_val = 0;
            for (int bit = 0; bit < 31; ++bit) {
                if (bit_counts[bit] > 0) {
                    current_val |= (1LL << bit);
                    bit_counts[bit]--;
                }
            }
            long long square = (current_val * current_val) % MOD;
            max_sum_squares = (max_sum_squares + square) % MOD;
        }

        return max_sum_squares;
    }
};