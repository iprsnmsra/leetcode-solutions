#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> ans(n);

        vector<int> last_pos(30, 0); 

        for (int i = n - 1; i >= 0; --i) {

            int max_end = i; 
            
            for (int bit = 0; bit < 30; ++bit) {

                if ((nums[i] >> bit) & 1) {
                    last_pos[bit] = i;
                }
                if (last_pos[bit] > 0) {
                    max_end = max(max_end, last_pos[bit]);
                }
            }

            ans[i] = max_end - i + 1;
        }

        return ans;
    }
};