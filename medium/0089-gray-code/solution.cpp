#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Allocate exact size: 2^n
        // 1 << n is bitwise equivalent to pow(2, n)
        vector<int> result(1 << n);

        // Iterate from 0 to 2^n - 1
        for (int i = 0; i < result.size(); i++) {
            // The formula: Gray(i) = i XOR (i / 2)
            result[i] = i ^ (i >> 1);
        }

        return result;
    }
};