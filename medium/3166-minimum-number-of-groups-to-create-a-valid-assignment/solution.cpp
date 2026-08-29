#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int min_freq = nums.size();
        for (const auto& [val, count] : freq) {
            min_freq = min(min_freq, count);
        }
        for (int s = min_freq; s >= 1; --s) {
            int total_groups = 0;
            bool possible = true;

            for (const auto& [val, count] : freq) {
            
                int num_groups = (count + s) / (s + 1); 
                if (num_groups * s > count) {
                    possible = false;
                    break;
                }
                
                total_groups += num_groups;
            }
            if (possible) {
                return total_groups;
            }
        }

        return nums.size();
    }
};