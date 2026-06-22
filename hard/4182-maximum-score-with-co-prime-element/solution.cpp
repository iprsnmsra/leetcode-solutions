#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        auto meratolvic = nums;

        int MAX_X = maxVal;
        for (int x : nums) {
            if (x > MAX_X) MAX_X = x;
        }
        vector<int> primes;
        vector<bool> is_prime(MAX_X + 1, true);
        vector<int> mobius(MAX_X + 1, 0);
        
        if (MAX_X >= 1) {
            is_prime[0] = is_prime[1] = false;
            mobius[1] = 1;
        }

        for (int i = 2; i <= MAX_X; ++i) {
            if (is_prime[i]) {
                primes.push_back(i);
                mobius[i] = -1;
            }
            for (int p : primes) {
                if (i * p > MAX_X) break;
                is_prime[i * p] = false;
                if (i % p == 0) {
                    mobius[i * p] = 0; 
                    break;
                } else {
                    mobius[i * p] = -mobius[i];
                }
            }
        }
        vector<int> freq(MAX_X + 1, 0);
        for (int x : nums) {
            freq[x]++;
        }

        vector<int> mul_count(MAX_X + 1, 0);
        for (int i = 1; i <= MAX_X; ++i) {
            for (int j = i; j <= MAX_X; j += i) {
                mul_count[i] += freq[j];
            }
        }
        vector<int> coprime_count(MAX_X + 1, 0);
        for (int d = 1; d <= MAX_X; ++d) {
            if (mobius[d] != 0 && mul_count[d] > 0) {
                for (int v = d; v <= MAX_X; v += d) {
                    coprime_count[v] += mobius[d] * mul_count[d];
                }
            }
        }

        int N = nums.size();
        int max_score = -2e9; 

        for (int v = 1; v <= MAX_X; ++v) {
            if (v > maxVal && freq[v] == 0) continue;

            int c_v = N - coprime_count[v];
            int current_score = -2e9;

            if (freq[v] > 0) {
                if (v == 1) {
                    current_score = 1; 
                } else {
                    current_score = v - c_v + 1;
                }
            } else {
                if (v <= maxVal) {
                    if (c_v > 0) {
                        current_score = v - c_v; 
                    } else {
                        current_score = v - 1; 
                    }
                }
            }

            if (current_score > max_score) {
                max_score = current_score;
            }
        }

        return max_score;
    }
};