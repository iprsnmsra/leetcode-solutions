#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    // FIXED: Renamed from minAbsoluteDifference to minAbsDiff
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        vector<int> window;
        window.reserve(k * k); // Hardware empathy: pre-allocate memory!

        // Loop over every possible top-left corner of the sliding window
        for (int r = 0; r <= m - k; ++r) {
            for (int c = 0; c <= n - k; ++c) {
                
                window.clear(); // Reset the size to 0, but keep capacity intact
                
                // Extract the k x k submatrix
                for (int wr = 0; wr < k; ++wr) {
                    for (int wc = 0; wc < k; ++wc) {
                        window.push_back(grid[r + wr][c + wc]);
                    }
                }

                // Sort the flat window to easily find the smallest differences
                sort(window.begin(), window.end());

                int min_diff = INT_MAX;
                int distinct_count = 1;

                // Scan adjacent elements to find the minimum difference between DISTINCT values
                for (int i = 1; i < window.size(); ++i) {
                    if (window[i] != window[i - 1]) {
                        distinct_count++;
                        min_diff = min(min_diff, window[i] - window[i - 1]);
                    }
                }

                // If all elements are the same (or it's a 1x1 window), return 0
                if (distinct_count <= 1) {
                    ans[r][c] = 0;
                } else {
                    ans[r][c] = min_diff;
                }
            }
        }

        return ans;
    }
};