#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        int valid_count = 0;

        // Hardware Empathy: We only need two 1D arrays to track the 2D prefix sums!
        vector<int> col_X(n, 0);
        vector<int> col_Y(n, 0);

        for (int r = 0; r < m; ++r) {
            int row_X = 0; // Tracks 'X' count for the current row
            int row_Y = 0; // Tracks 'Y' count for the current row
            
            for (int c = 0; c < n; ++c) {
                // 1. Accumulate the current row
                if (grid[r][c] == 'X') {
                    row_X++;
                } else if (grid[r][c] == 'Y') {
                    row_Y++;
                }
                
                // 2. Add row accumulation to our running column total
                // This magically converts a 1D row sum into a perfect 2D prefix sum!
                col_X[c] += row_X;
                col_Y[c] += row_Y;
                
                // 3. Evaluate the submatrix ending at (r, c)
                if (col_X[c] > 0 && col_X[c] == col_Y[c]) {
                    valid_count++;
                }
            }
        }

        return valid_count;
    }
};