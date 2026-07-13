#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> result;
        for (int len = 2; len <= 9; ++len) {
            for (int start_digit = 1; start_digit <= 10 - len; ++start_digit) {
                
                int num = 0;
                int current_digit = start_digit;
                for (int i = 0; i < len; ++i) {
                    num = num * 10 + current_digit;
                    current_digit++;
                }
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};