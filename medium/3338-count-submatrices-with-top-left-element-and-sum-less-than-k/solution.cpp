#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        int valid_count = 0;

        for (int r = 0; r < m; ++r) {
            
            int row_sum = 0; // Tracks the 1D sum of the current row
            
            for (int c = 0; c < n; ++c) {
                // 1. Accumulate the current row
                row_sum += grid[r][c];
                
                // 2. Add the 2D prefix sum from the cell directly above us
                int top_prefix = (r > 0) ? grid[r - 1][c] : 0;
                int current_prefix = top_prefix + row_sum;
                
                // 3. Evaluate and Prune
                if (current_prefix <= k) {
                    valid_count++;
                    grid[r][c] = current_prefix; // Store in-place for the next row
                } else {
                    // Cap the value at k + 1 to prevent integer overflow on massive grids.
                    // This still correctly signals to the rows below that the limit is breached.
                    grid[r][c] = k + 1; 
                    
                    // EARLY EXIT: The rest of this row will strictly be > k. Stop looping!
                    break; 
                }
            }
            
            // SUPER EARLY EXIT: If the very first column of this row exceeded k, 
            // no cells in any of the rows below it can possibly be valid. 
            if (grid[r][0] > k) {
                break;
            }
        }

        return valid_count;
    }
};