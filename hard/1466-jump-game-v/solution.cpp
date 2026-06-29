#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = arr.size();
        vector<int> memo(n, 0);
        int global_max_jumps = 0;

        for (int i = 0; i < n; ++i) {
            global_max_jumps = max(global_max_jumps, dfs(arr, d, i, memo));
        }

        return global_max_jumps;
    }

private:
    int dfs(const vector<int>& arr, int d, int i, vector<int>& memo) {
        if (memo[i] != 0) {
            return memo[i];
        }

        int n = arr.size();
        int max_sub_jumps = 0;

        for (int step = 1; step <= d; ++step) {
            int right_idx = i + step;
            if (right_idx >= n) break; 
            if (arr[right_idx] >= arr[i]) break; 
            
            max_sub_jumps = max(max_sub_jumps, dfs(arr, d, right_idx, memo));
        }

        for (int step = 1; step <= d; ++step) {
            int left_idx = i - step;
            if (left_idx < 0) break; 
            if (arr[left_idx] >= arr[i]) break; 
            
            max_sub_jumps = max(max_sub_jumps, dfs(arr, d, left_idx, memo));
        }

        memo[i] = 1 + max_sub_jumps;
        return memo[i];
    }
};