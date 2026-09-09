#include <iostream>

using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long total_commas = 0;
        long long base = 1000;
        while (n >= base) {
            total_commas += (n - base + 1);
            base *= 1000;
        }

        return total_commas;
    }
};