#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result;
        result.reserve(20);

        for (int i = 0; i < 13; ++i) {
            while (num >= values[i]) {
                num -= values[i];
                result += symbols[i];
            }
        }

        return result;
    }
};