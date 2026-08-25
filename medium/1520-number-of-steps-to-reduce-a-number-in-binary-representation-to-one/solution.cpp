#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int steps = 0;
        int carry = 0;
        for (int i = s.length() - 1; i > 0; --i) {
            
            int bit = (s[i] - '0') + carry;

            if (bit % 2 == 1) {
                steps += 2;
                carry = 1;
            } else {
                steps += 1;
            }
        }
        return steps + carry;
    }
};