#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    void backtrack(vector<int>& nums, int start_index, vector<vector<int>>& result) {
        if (start_index == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start_index; i < nums.size(); ++i) {
            swap(nums[start_index], nums[i]);
            backtrack(nums, start_index + 1, result);
            swap(nums[start_index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> result;
        result.reserve(720); 
        backtrack(nums, 0, result);

        return result;
    }
};