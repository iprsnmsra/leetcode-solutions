#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = board.size();
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp_sum(n, vector<int>(n, -1));
        vector<vector<int>> dp_paths(n, vector<int>(n, 0));
        dp_sum[n - 1][n - 1] = 0;
        dp_paths[n - 1][n - 1] = 1;
        int dr[] = {1, 0, 1}; 
        int dc[] = {0, 1, 1};
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (board[r][c] == 'X' || (r == n - 1 && c == n - 1)) continue;

                int max_prev_sum = -1;
                int paths = 0;
                for (int i = 0; i < 3; ++i) {
                    int prev_r = r + dr[i];
                    int prev_c = c + dc[i];
                    if (prev_r < n && prev_c < n && dp_sum[prev_r][prev_c] != -1) {
                        
                        if (dp_sum[prev_r][prev_c] > max_prev_sum) {
                            max_prev_sum = dp_sum[prev_r][prev_c];
                            paths = dp_paths[prev_r][prev_c];
                        } 
                        else if (dp_sum[prev_r][prev_c] == max_prev_sum) {
                            paths = (paths + dp_paths[prev_r][prev_c]) % MOD;
                        }
                    }
                }
                if (max_prev_sum != -1) {
                    int cell_val = (board[r][c] == 'E') ? 0 : (board[r][c] - '0');
                    dp_sum[r][c] = max_prev_sum + cell_val;
                    dp_paths[r][c] = paths;
                }
            }
        }
        if (dp_sum[0][0] == -1) {
            return {0, 0};
        }

        return {dp_sum[0][0], dp_paths[0][0]};
    }
};