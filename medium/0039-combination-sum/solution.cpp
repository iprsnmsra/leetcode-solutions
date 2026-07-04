#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> result;
        vector<int> current;
        
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, current, result);
        
        return result;
    }
    
private:
    void backtrack(const vector<int>& candidates, int target, int start_index, 
                   vector<int>& current, vector<vector<int>>& result) {
        
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start_index; i < candidates.size(); ++i) {

            if (target - candidates[i] < 0) {
                break;
            }
            current.push_back(candidates[i]);

            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};