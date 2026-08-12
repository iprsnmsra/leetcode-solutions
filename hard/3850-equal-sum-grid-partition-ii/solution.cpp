#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
private:

    bool checkHorizontal(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m < 2) return false;

        long long total_sum = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                total_sum += grid[r][c];
            }
        }

        if (n == 1) {
            long long s_top = 0, s_bot = total_sum;
            for (int r = 0; r < m - 1; ++r) {
                s_top += grid[r][0];
                s_bot -= grid[r][0];
                long long diff = s_top - s_bot;
                
                if (diff == 0) return true;
                
                if (diff > 0) {
                    if (r + 1 >= 2) {
                        if (diff == grid[0][0] || diff == grid[r][0]) return true;
                    }
                } else {
                    long long target = -diff;
                    if (m - 1 - r >= 2) {
                        if (target == grid[r + 1][0] || target == grid[m - 1][0]) return true;
                    }
                }
            }
            return false;
        }

        vector<int> in_top(100005, 0);
        vector<int> in_bot(100005, 0);

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] <= 100000) in_bot[grid[r][c]]++;
            }
        }

        long long s_top = 0, s_bot = total_sum;
        
        for (int r = 0; r < m - 1; ++r) {
            for (int c = 0; c < n; ++c) {
                int val = grid[r][c];
                if (val <= 100000) {
                    in_top[val]++;
                    in_bot[val]--;
                }
                s_top += val;
                s_bot -= val;
            }

            long long diff = s_top - s_bot;
            if (diff == 0) return true;

            if (diff > 0) {
                if (r == 0) { 
                    if (diff == grid[0][0] || diff == grid[0][n - 1]) return true;
                } else {
                    if (diff <= 100000 && in_top[diff] > 0) return true;
                }
            } else {
                long long target = -diff;
                if (r == m - 2) { 
                    if (target == grid[m - 1][0] || target == grid[m - 1][n - 1]) return true;
                } else {
                    if (target <= 100000 && in_bot[target] > 0) return true;
                }
            }
        }
        return false;
    }
    vector<vector<int>> transpose(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> t(n, vector<int>(m));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                t[c][r] = grid[r][c];
            }
        }
        return t;
    }

public:

    bool canPartitionGrid(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return checkHorizontal(grid) || checkHorizontal(transpose(grid));
    }
};