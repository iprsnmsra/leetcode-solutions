#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int max_digit = 0;

        for (char c : n) {
            int current_digit = c - '0';
            
            if (current_digit > max_digit) {
                max_digit = current_digit;
            }
            if (max_digit == 9) {
                return 9;
            }
        }

        return max_digit;
    }
};