#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};