#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int original = n;
        
        long long reversed_n = 0;

        while (n > 0) {
            int digit = n % 10;
            reversed_n = reversed_n * 10 + digit;
            n /= 10;
        }
        return abs(original - reversed_n);
    }
};