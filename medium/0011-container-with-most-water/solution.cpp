#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
     
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;

        while (left < right) {
  
            int h = min(height[left], height[right]);
           
            max_water = max(max_water, (right - left) * h);

        
            if (height[left] == h) {
                while (left < right && height[left] <= h) {
                    left++;
                }
            } else {
                while (left < right && height[right] <= h) {
                    right--;
                }
            }
        }
        
        return max_water;
    }
};