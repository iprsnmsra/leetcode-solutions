#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long n = s.length();
        long long zeros = 0;
        for (char ch : s) {
            if (ch == '0') {
                zeros++;
            }
        }
        if (zeros == 0) return 0;
        for (long long m = 1; m <= n + 2; ++m) {
            long long total_flips = m * k;
            if (total_flips < zeros) continue;
            if (total_flips % 2 != zeros % 2) continue;
            long long max_odd_flips  = (m % 2 == 1) ? m : (m - 1);
            long long max_even_flips = (m % 2 == 1) ? (m - 1) : m;
            long long max_flips_possible = (zeros * max_odd_flips) + ((n - zeros) * max_even_flips);
            if (total_flips <= max_flips_possible) {
                return m;
            }
        }
        return -1;
    }
};