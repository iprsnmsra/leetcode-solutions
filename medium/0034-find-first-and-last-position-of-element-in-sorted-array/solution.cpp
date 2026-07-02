#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int first = findBound(nums, target, true);
        if (first == -1) {
            return {-1, -1};
        }
        
        int last = findBound(nums, target, false);
        
        return {first, last};
    }

private:
    int findBound(const vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int bound = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid; 
                if (isFirst) {
                    right = mid - 1;
                } 
                else {
                    left = mid + 1;
                }
            } 
            else if (nums[mid] < target) {
                left = mid + 1; // Target is strictly to the right
            } 
            else {
                right = mid - 1; // Target is strictly to the left
            }
        }

        return bound;
    }
};