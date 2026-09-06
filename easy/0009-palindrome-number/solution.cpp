#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
      
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + (x % 10);
            x /= 10;
        }
        return x == reversedHalf || x == reversedHalf / 10;
    }
};