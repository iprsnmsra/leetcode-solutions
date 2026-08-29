#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (areAlmostEqual(nums[i], nums[j])) {
                    count++;
                }
            }
        }

        return count;
    }

private:
    bool areAlmostEqual(int x, int y) {
        string sx = to_string(x);
        string sy = to_string(y);
        int max_len = max(sx.length(), sy.length());
        if (sx.length() < max_len) sx = string(max_len - sx.length(), '0') + sx;
        if (sy.length() < max_len) sy = string(max_len - sy.length(), '0') + sy;
        vector<int> diffs;
        for (int i = 0; i < max_len; ++i) {
            if (sx[i] != sy[i]) {
                diffs.push_back(i);
            }
        }
        if (diffs.empty()) {
            return true; 
        } 
        if (diffs.size() == 2) {
            int idx1 = diffs[0];
            int idx2 = diffs[1];
            return (sx[idx1] == sy[idx2]) && (sx[idx2] == sy[idx1]);
        }
        return false;
    }
};