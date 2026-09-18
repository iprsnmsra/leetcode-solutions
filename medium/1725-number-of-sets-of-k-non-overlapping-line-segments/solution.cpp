#include <iostream>

using namespace std;

class Solution {
private:
    long long modInverse(long long base, long long mod) {
        long long res = 1;
        long long exp = mod - 2;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int numberOfSets(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long mod = 1e9 + 7;
        int N_total = n + k - 1;
        int K_total = 2 * k;
        if (K_total > N_total) return 0;

        long long num = 1;
        long long den = 1;
        for (int i = 1; i <= K_total; ++i) {
            num = (num * (N_total - i + 1)) % mod;
            den = (den * i) % mod;
        }
        long long ans = (num * modInverse(den, mod)) % mod;
        return ans;
    }
};