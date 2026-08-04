#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        bool present[101] = {false};
        
        int min_val = 101;
        int max_val = 0;
        for (int num : nums) {
            present[num] = true;
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }

        vector<int> missing;
        int expected_missing = (max_val - min_val + 1) - nums.size();
        
        if (expected_missing > 0) {
            missing.reserve(expected_missing);
            
            for (int i = min_val + 1; i < max_val; ++i) {
                if (!present[i]) {
                    missing.push_back(i);
                }
            }
        }

        return missing;
    }
};