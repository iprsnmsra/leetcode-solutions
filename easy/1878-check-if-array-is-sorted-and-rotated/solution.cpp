#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int drop_count = 0;

        for (int i = 0; i < n; ++i) {

            if (nums[i] > nums[(i + 1) % n]) {
                drop_count++;
            }

            if (drop_count > 1) {
                return false;
            }
        }

        return true;
    }
};