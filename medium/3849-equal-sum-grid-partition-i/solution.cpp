#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // FIXED: Renamed to strictly match LeetCode's expected 'canPartitionGrid'
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        
        vector<long long> row_sums(m, 0);
        vector<long long> col_sums(n, 0);
        long long total_sum = 0;

        // 1. Single Pass: Project the 2D grid into 1D row and column sums
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int val = grid[r][c];
                row_sums[r] += val;
                col_sums[c] += val;
                total_sum += val;
            }
        }

        // 2. Impossible State: An odd total cannot be split into two equal integer halves
        if (total_sum % 2 != 0) {
            return false;
        }
        
        long long target = total_sum / 2;

        // 3. Test Horizontal Cuts (Sweep row projections)
        long long current_sum = 0;
        // We loop up to m - 1 to ensure the bottom section is never empty
        for (int r = 0; r < m - 1; ++r) {
            current_sum += row_sums[r];
            if (current_sum == target) {
                return true;
            }
        }

        // 4. Test Vertical Cuts (Sweep column projections)
        current_sum = 0;
        // We loop up to n - 1 to ensure the right section is never empty
        for (int c = 0; c < n - 1; ++c) {
            current_sum += col_sums[c];
            if (current_sum == target) {
                return true;
            }
        }

        return false;
    }
};