#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int min_val = 2e9; 
        bool has_odd = false;
        for (int x : nums1) {
            if (x < min_val) {
                min_val = x;
            }
            if (x % 2 != 0) {
                has_odd = true;
            }
        }
        return (min_val % 2 != 0) || !has_odd;
    }
};