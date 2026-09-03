#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int map[128] = {0};
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int result = 0;
        int prev = 0; // Value of the previously processed character (to the right)

        // Iterate backwards
        for (int i = s.length() - 1; i >= 0; i--) {
            int curr = map[s[i]];

            if (curr < prev) {
                result -= curr;
            } else {
                result += curr;
                prev = curr; 
            }
        }

        return result;
    }
};