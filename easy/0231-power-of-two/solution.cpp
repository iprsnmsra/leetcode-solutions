#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return n > 0 && (n & (n - 1)) == 0;
    }
};