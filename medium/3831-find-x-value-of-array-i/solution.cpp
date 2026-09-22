#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // 1. Data Abstraction: 64-Bit Tally Registers
        // Using 'long long' perfectly shields against N(N+1)/2 combinatorial overflow bounds
        vector<long long> res(k, 0);
        vector<long long> freq(k, 0);
        vector<long long> next_freq(k, 0);

        // 2. The Linear Hardware Sweep
        for (int num : nums) {
            int v = num % k;
            
            // Clear the ping-pong hardware register for the next state transition
            fill(next_freq.begin(), next_freq.end(), 0);
            
            // 3. Modulo State Multiplication
            // Because k <= 5, this loop operates purely within the CPU's unrolled ALU registers
            for (int y = 0; y < k; ++y) {
                if (freq[y] > 0) {
                    next_freq[(y * v) % k] += freq[y];
                }
            }
            
            // Register the element serving as a standalone contiguous subarray
            next_freq[v]++;
            
            // 4. Global Accumulation and Register Overwrite
            for (int i = 0; i < k; ++i) {
                res[i] += next_freq[i];
                freq[i] = next_freq[i];
            }
        }

        return res;
    }
};