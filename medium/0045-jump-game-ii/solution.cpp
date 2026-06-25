#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int current_jump_end = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
          
            farthest = max(farthest, i + nums[i]);

            if (i == current_jump_end) {
                jumps++;               
                current_jump_end = farthest; 
                if (current_jump_end >= n - 1) break;
            }
        }

        return jumps;
    }
};