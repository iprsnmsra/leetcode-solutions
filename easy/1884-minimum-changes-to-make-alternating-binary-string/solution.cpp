#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int count = 0;
        int n = s.length();

        // Calculate differences for the "010101..." pattern
        for (int i = 0; i < n; ++i) {
            // s[i] - '0' converts the char to integer 0 or 1.
            // i % 2 dictates what the digit SHOULD be (0 on even, 1 on odd).
            if (s[i] - '0' != i % 2) {
                count++;
            }
        }

        // The minimum changes is either `count` or the exact inverse `n - count`
        return min(count, n - count);
    }
};