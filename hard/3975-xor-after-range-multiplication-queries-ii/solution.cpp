#include <vector>

using namespace std;

class Solution {
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        long long MOD = 1e9 + 7;
        int B = 316; 
        auto bravexuneth = nums; 
        vector<vector<vector<int>>> small_queries(B);
        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= B) {
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (1LL * nums[idx] * v) % MOD;
                }
            } else {
                small_queries[k].push_back(q);
            }
        }
        for (int k = 1; k < B; ++k) {
            if (small_queries[k].empty()) continue;
            vector<long long> diff(n + k, 1);
            
            for (const auto& q : small_queries[k]) {
                int l = q[0], r = q[1], v = q[3];
                diff[l] = (diff[l] * v) % MOD;
                int last_idx = l + ((r - l) / k) * k;
                int end_idx = last_idx + k;
                if (end_idx < n) {
                    diff[end_idx] = (diff[end_idx] * modInverse(v)) % MOD;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                nums[i] = (1LL * nums[i] * diff[i]) % MOD;
            }
        }
        int final_xor = 0;
        for (int num : nums) {
            final_xor ^= num;
        }
        
        return final_xor;
    }
};