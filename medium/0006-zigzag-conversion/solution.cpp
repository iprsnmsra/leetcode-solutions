#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;

        int n = s.length();
        string result;
        result.reserve(n);

        int cycle = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += cycle) {
                result += s[j];
                
                int diagonal_idx = j + cycle - 2 * i;
                
                if (i != 0 && i != numRows - 1 && diagonal_idx < n) {
                    result += s[diagonal_idx];
                }
            }
        }
        
        return result;
    }
};