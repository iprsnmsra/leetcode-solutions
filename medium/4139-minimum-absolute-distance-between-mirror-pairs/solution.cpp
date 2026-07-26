#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int, int> last_seen_reversed;
        int min_dist = INT_MAX;

        for (int j = 0; j < nums.size(); ++j) {

            if (last_seen_reversed.find(nums[j]) != last_seen_reversed.end()) {
                int current_dist = j - last_seen_reversed[nums[j]];
                if (current_dist < min_dist) {
                    min_dist = current_dist;
                }
            }

            int rev = 0;
            int temp = nums[j];
            while (temp > 0) {
                rev = rev * 10 + (temp % 10);
                temp /= 10;
            }

            last_seen_reversed[rev] = j;
        }
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};