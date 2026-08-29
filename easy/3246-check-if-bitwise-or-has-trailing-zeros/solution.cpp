#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int even_count = 0;

        for (int num : nums) {
            if ((num & 1) == 0) {
                even_count++;
            }
            if (even_count >= 2) {
                return true;
            }
        }

        return false;
    }
};