#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (sum > 9LL * num) {
            return "";
        }

        string result;
        result.reserve(num); 
        for (int i = 0; i < num; ++i) {
          
            int d = min(9, sum);
            result += (char)('0' + d);
            sum -= d;
        }

        return result;
    }
};