#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int max_ones = 0, max_zeros = 0;
        int curr_ones = 0, curr_zeros = 0;

        for (char c : s) {
            if (c == '1') {
                curr_ones++;
                curr_zeros = 0;
                if (curr_ones > max_ones) {
                    max_ones = curr_ones;
                }
            } else {
                curr_zeros++;
                curr_ones = 0; 
                if (curr_zeros > max_zeros) {
                    max_zeros = curr_zeros;
                }
            }
        }
        return max_ones > max_zeros;
    }
};