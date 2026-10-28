#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Optimization: Fast I/O execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Initialize grid filled entirely with obstacles '#'
        vector<string> grid(m, string(n, '#'));

        // 1. Fill the entire top row (row 0) with free cells '.'
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }

        // 2. Fill the entire rightmost column (column n - 1) with free cells '.'
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};