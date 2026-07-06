#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end());

        backtrack(nums, 0, current, result);
        
        return result;
    }
    
private:
    void backtrack(const vector<int>& nums, int start_index, 
                   vector<int>& current, vector<vector<int>>& result) {

        result.push_back(current);

        for (int i = start_index; i < nums.size(); ++i) {

            if (i > start_index && nums[i] == nums[i - 1]) {
                continue;
            }

            current.push_back(nums[i]);

            backtrack(nums, i + 1, current, result);

            current.pop_back();
        }
    }
};