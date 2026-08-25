#include <iostream>

using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long val = 0;
        int MOD = 1e9 + 7;
        int bit_length = 0;

        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) {
                bit_length++;
            }
            val = ((val << bit_length) | i) % MOD;
        }

        return val;
    }
};