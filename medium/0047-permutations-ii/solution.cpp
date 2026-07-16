#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());
        
        backtrack(nums, used, current, result);
        
        return result;
    }
    
private:
    void backtrack(const vector<int>& nums, vector<bool>& used, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, used, current, result);
            used[i] = false;
            current.pop_back();
        }
    }
};