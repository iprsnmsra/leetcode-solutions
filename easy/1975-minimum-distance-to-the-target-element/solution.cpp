#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int min_dist = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                int curr_dist = abs(i - start);
                
                if (curr_dist < min_dist) {
                    min_dist = curr_dist;
                }
                
                if (min_dist == 0) {
                    break;
                }
            }
        }

        return min_dist;
    }
};