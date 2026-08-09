#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int left = 0;
        int zero_count = 0;
        int max_window = 0;
        for (int right = 0; right < nums.size(); ++right) {
            
            if (nums[right] == 0) {
                zero_count++;
            }
            while (zero_count > 1) {
                if (nums[left] == 0) {
                    zero_count--; 
                }
                left++; 
            }
            max_window = max(max_window, right - left);
        }

        return max_window;
    }
};