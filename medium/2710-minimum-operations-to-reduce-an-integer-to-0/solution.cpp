#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int ops = 0;
        while (n > 0) {
            if ((n & 1) == 1) {
                if ((n & 2) == 2) {
                    n += 1;
                } 
                else {
                    n -= 1;
                }
                ops++;
            }
            n >>= 1;
        }

        return ops;
    }
};