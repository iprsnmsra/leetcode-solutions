#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (k < 0) return 0;

        unordered_map<int, int> freq;
        int count = 0;

        for (int num : nums) {
            freq[num]++;
        }
        for (auto const& [key, value] : freq) {
            if (k == 0) {

                if (value >= 2) {
                    count++;
                }
            } else {

                if (freq.count(key + k)) {
                    count++;
                }
            }
        }

        return count;
    }
};