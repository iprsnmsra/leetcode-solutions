#include <vector>
#include <numeric> 
#include <iostream>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int min_val = 1000;
        int max_val = 1;
        for (int num : nums) {
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }
        return std::gcd(min_val, max_val);
    }
};