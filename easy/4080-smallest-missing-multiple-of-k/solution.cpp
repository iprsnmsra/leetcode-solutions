#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        bool present[101] = {false};
        for (int num : nums) {
            present[num] = true;
        }
        int target = k;
        while (target <= 100 && present[target]) {
            target += k;
        }

        return target;
    }
};