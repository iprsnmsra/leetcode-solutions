#include <vector>
#include <algorithm>
#include <iostream>
#include <utility> 

using namespace std;

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prev_dp(n, vector<int>(k + 1, -1));

        prev_dp[0][0] = 0;

        for (int r = 0; r < m; ++r) {
            vector<vector<int>> curr_dp(n, vector<int>(k + 1, -1));
            
            for (int c = 0; c < n; ++c) {
                if (r == 0 && c == 0) {
                    curr_dp[0][0] = 0;
                    continue;
                }

                int val = grid[r][c];
                int cell_cost = (val > 0) ? 1 : 0;
                int cell_score = val;

                if (cell_cost > k) continue; 

                for (int curr_k = cell_cost; curr_k <= k; ++curr_k) {
                    int prev_k = curr_k - cell_cost;
                    int max_prev = -1;

                    if (r > 0 && prev_dp[c][prev_k] != -1) {
                        max_prev = max(max_prev, prev_dp[c][prev_k]);
                    }

                    if (c > 0 && curr_dp[c - 1][prev_k] != -1) {
                        max_prev = max(max_prev, curr_dp[c - 1][prev_k]);
                    }

                    if (max_prev != -1) {
                        curr_dp[c][curr_k] = max_prev + cell_score;
                    }
                }
            }
            prev_dp = std::move(curr_dp);
        }
        int max_final_score = -1;
        for (int curr_k = 0; curr_k <= k; ++curr_k) {
            if (prev_dp[n - 1][curr_k] != -1) {
                max_final_score = max(max_final_score, prev_dp[n - 1][curr_k]);
            }
        }

        return max_final_score;
    }
};