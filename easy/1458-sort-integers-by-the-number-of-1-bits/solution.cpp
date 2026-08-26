#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            int count_a = __builtin_popcount(a);
            int count_b = __builtin_popcount(b);
            if (count_a == count_b) {
                return a < b;
            }
            return count_a < count_b;
        });

        return arr;
    }
};