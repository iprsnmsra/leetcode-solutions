#include <string>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (str1 + str2 != str2 + str1) {
            return "";
        }

        int gcd_length = std::gcd(str1.length(), str2.length());

        return str1.substr(0, gcd_length);
    }
};