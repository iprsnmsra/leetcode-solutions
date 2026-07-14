class Solution {
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int numberOfWays(int startPos, int endPos, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int d = abs(endPos - startPos);
        if (d > k || (k + d) % 2 != 0) {
            return 0;
        }

        int r = (k + d) / 2;
        long long MOD = 1e9 + 7;
        long long num = 1;
        long long den = 1;
        if (r > k - r) {
            r = k - r; 
        }

        for (int i = 1; i <= r; ++i) {
            num = (num * (k - i + 1)) % MOD;
            den = (den * i) % MOD;
        }
        long long denInverse = power(den, MOD - 2, MOD);

        return (num * denInverse) % MOD;
    }
};