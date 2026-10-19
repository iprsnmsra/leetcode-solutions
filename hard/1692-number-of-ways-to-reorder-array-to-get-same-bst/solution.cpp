#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;
    long long fact[1005];
    long long invFact[1005];
    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }
    long long getWays(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1; 
        int root = nums[0];
        vector<int> left, right;
        left.reserve(n); 
        right.reserve(n);
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        long long waysLeft = getWays(left);
        long long waysRight = getWays(right);
        long long interleavings = nCr(n - 1, left.size());

        return (interleavings * waysLeft % MOD) * waysRight % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 1; --i) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
        return (getWays(nums) - 1 + MOD) % MOD;
    }
};