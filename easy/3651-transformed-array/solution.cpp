#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            int target_index = ((i + nums[i]) % n + n) % n;
            result[i] = nums[target_index];
        }

        return result;
    }
};