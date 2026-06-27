#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<long long, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int max_len = 1;
        if (count.count(1)) {
            int ones = count[1];
            if (ones % 2 == 0) ones--;
            max_len = max(max_len, ones);
        }
        for (auto const& [key, val] : count) {
            if (key == 1) continue;

            long long curr = key;
            int curr_len = 0;
            while (count.count(curr) && count[curr] >= 2) {
                curr_len += 2;
                curr = curr * curr;
            }
            if (count.count(curr)) {
                curr_len += 1;
            } else {
                curr_len -= 1;
            }

            max_len = max(max_len, curr_len);
        }

        return max_len;
    }
};