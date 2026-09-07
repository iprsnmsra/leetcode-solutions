#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Edge Case: Overflow
        // INT_MIN / -1 = 2147483648, which > INT_MAX
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign of the result
        // If (dividend < 0) XOR (divisor < 0) is true, signs are different -> result is negative
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long to safely handle abs(INT_MIN)
        long n = labs((long)dividend);
        long d = labs((long)divisor);
        long quotient = 0;

        // "Double and Subtract" Strategy
        while (n >= d) {
            long temp = d;
            long multiple = 1;

            // Exponentially increase the divisor chunk by doubling it (Left Shift)
            // We check (temp << 1) <= n to ensuring we don't overshoot
            while ((temp << 1) <= n) {
                temp <<= 1;
                multiple <<= 1;
            }

            n -= temp;
            quotient += multiple;
        }

        return negative ? -quotient : quotient;
    }
};