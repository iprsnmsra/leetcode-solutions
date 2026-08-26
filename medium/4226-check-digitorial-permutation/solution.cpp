#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        
        long long target_sum = 0;
        vector<int> digit_counts(10, 0);
        int original_n = n;
        int num_digits = 0;
        while (n > 0) {
            int digit = n % 10;
            target_sum += fact[digit];
            digit_counts[digit]++;
            num_digits++;
            n /= 10;
        }
        

        long long temp = target_sum;
        int target_digits = 0;
        
        while (temp > 0) {
            int digit = temp % 10;
            digit_counts[digit]--;
            target_digits++;
            temp /= 10;
        }
        
        if (num_digits != target_digits) {
            return false;
        }
        for (int i = 0; i < 10; ++i) {
            if (digit_counts[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};