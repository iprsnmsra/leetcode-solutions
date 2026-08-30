#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int prime_count = 0;
        const int PRIME_MASK = 665772;

        for (int i = left; i <= right; ++i) {
            int set_bits = __builtin_popcount(i);
            if ((1 << set_bits) & PRIME_MASK) {
                prime_count++;
            }
        }

        return prime_count;
    }
};