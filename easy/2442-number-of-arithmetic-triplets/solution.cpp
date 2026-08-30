#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        bool seen[201] = {false};
        int count = 0;

        for (int num : nums) {
            seen[num] = true;
            if (num >= 2 * diff) {
                if (seen[num - diff] && seen[num - 2 * diff]) {
                    count++;
                }
            }
        }

        return count;
    }
};