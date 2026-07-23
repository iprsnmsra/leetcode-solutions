#include <iostream>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int flips = 0;

        while (a > 0 || b > 0 || c > 0) {
            int bit_a = a & 1;
            int bit_b = b & 1;
            int bit_c = c & 1;
            if (bit_c == 1) {
                if (bit_a == 0 && bit_b == 0) {
                    flips += 1;
                }
            } else {
                flips += (bit_a + bit_b);
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};