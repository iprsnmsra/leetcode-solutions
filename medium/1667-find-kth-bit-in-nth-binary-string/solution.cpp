#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int invert_count = 0;
        int len = (1 << n) - 1; 
        while (k > 1) {
            int middle = len / 2 + 1;

            if (k == middle) {
                return (invert_count % 2 == 0) ? '1' : '0';
            }
            
            if (k > middle) {
                k = len - k + 1;
                invert_count++; 
            }
            len /= 2;
        }
        return (invert_count % 2 == 0) ? '0' : '1';
    }
};