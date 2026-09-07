#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (nums.empty()) return 0;

        // 'k' acts as the "writer" pointer.
        // Index 0 is always unique, so we start writing from index 1.
        int k = 1;

        // 'i' acts as the "reader" or "scanner" pointer.
        for (int i = 1; i < nums.size(); i++) {
            // Because the array is sorted, we only need to compare 
            // current element with the previous one.
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // Overwrite the next unique slot
                k++;               // Move the writer forward
            }
        }

        return k;
    }
};