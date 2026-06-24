#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest_streak = 0;

        for (int num : num_set) {

            if (!num_set.count(num - 1)) {
                
                int current_num = num;
                int current_streak = 1;

                while (num_set.count(current_num + 1)) {
                    current_num += 1;
                    current_streak += 1;
                }
                longest_streak = max(longest_streak, current_streak);
            }
        }

        return longest_streak;
    }
};