#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int k = 0; // The writer pointer
        
        for (int i = 0; i < nums.size(); ++i) {
            // If the current element is NOT the value to remove, 
            // we keep it by writing it to the 'k' position.
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};