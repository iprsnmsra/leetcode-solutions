#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int countSpecialNumbers(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string s = to_string(n);
        int len = s.length();
        int res = 0;

        for (int i = 1; i < len; ++i) {
            res += 9 * permutation(9, i - 1); 
        }

        int seen_mask = 0; 
        
        for (int i = 0; i < len; ++i) {
            int current_digit = s[i] - '0';

            for (int d = (i == 0 ? 1 : 0); d < current_digit; ++d) {

                if ((seen_mask & (1 << d)) == 0) {
                    res += permutation(9 - i, len - i - 1);
                }
            }

            if ((seen_mask & (1 << current_digit)) != 0) {
                break; 
            }
            seen_mask |= (1 << current_digit); 

            if (i == len - 1) {
                res += 1;
            }
        }

        return res;
    }

private:
    int permutation(int m, int k) {
        if (k == 0) return 1;
        int res = 1;
        for (int i = 0; i < k; ++i) {
            res *= (m - i);
        }
        return res;
    }
};