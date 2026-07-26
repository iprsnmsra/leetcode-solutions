#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> results;
        vector<int> current_path;

        backtrack(k, n, 1, current_path, results);
        
        return results;
    }
    
private:
    void backtrack(int k_remaining, int target_sum, int start_num, vector<int>& current_path, vector<vector<int>>& results) {
        if (k_remaining == 0 && target_sum == 0) {
            results.push_back(current_path);
            return;
        }

        if (k_remaining == 0 || target_sum < 0) {
            return;
        }

        for (int i = start_num; i <= 9; ++i) {

            if (i > target_sum) {
                break;
            }

            current_path.push_back(i);

            backtrack(k_remaining - 1, target_sum - i, i + 1, current_path, results);

            current_path.pop_back();
        }
    }
};