#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int first = INT_MAX;
        int second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                first = num;
            } else if (num <= second) {
                
                second = num;
            } else {
                return true;
            }
        }

        return false;
    }
};