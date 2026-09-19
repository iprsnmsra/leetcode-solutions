class Solution {
public:
    int countDigitOne(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long total_ones = 0;
        for (long long m = 1; m <= n; m *= 10) {
            long long left = n / (m * 10);
            long long curr = (n / m) % 10;
            long long right = n % m;
            if (curr == 0) {
                total_ones += left * m;
            } else if (curr == 1) {
                total_ones += left * m + right + 1;
            } else {
                total_ones += (left + 1) * m;
            }
        }

        return total_ones;
    }
};