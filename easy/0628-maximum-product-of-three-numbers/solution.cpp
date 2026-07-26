#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int max1 = INT_MIN; 
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX; 
        int min2 = INT_MAX;
        for (int num : nums) {
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }
            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }
        int reality_a = max1 * max2 * max3;
        int reality_b = min1 * min2 * max1;

        return max(reality_a, reality_b);
    }
};