#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int root = sqrt(n);
        if (root * root == n) {
            return 1;
        }

        int temp = n;
        while (temp % 4 == 0) {
            temp /= 4;
        }
        if (temp % 8 == 7) {
            return 4;
        }

        for (int i = 1; i * i <= n; ++i) {
            int remainder = n - i * i;
            int rem_root = sqrt(remainder);
            if (rem_root * rem_root == remainder) {
                return 2;
            }
        }
        return 3;
    }
};