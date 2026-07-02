#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void backtrack(int index, vector<int>& nums, vector<int>& current_subset, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current_subset);
            return;
        }
        current_subset.push_back(nums[index]);
        backtrack(index + 1, nums, current_subset, result);
        current_subset.pop_back();
        backtrack(index + 1, nums, current_subset, result);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> result;
        vector<int> current_subset;
        result.reserve(1 << nums.size());
        backtrack(0, nums, current_subset, result);

        return result;
    }
};