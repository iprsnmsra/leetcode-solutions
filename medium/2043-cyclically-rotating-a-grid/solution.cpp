#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();

        int num_layers = min(m, n) / 2;
        
        for (int layer = 0; layer < num_layers; ++layer) {
            int top = layer;
            int bottom = m - 1 - layer;
            int left = layer;
            int right = n - 1 - layer;
            
            vector<int> unrolled;

            for (int j = left; j <= right; ++j) unrolled.push_back(grid[top][j]);

            for (int i = top + 1; i <= bottom; ++i) unrolled.push_back(grid[i][right]);

            for (int j = right - 1; j >= left; --j) unrolled.push_back(grid[bottom][j]);

            for (int i = bottom - 1; i > top; --i) unrolled.push_back(grid[i][left]);

            int L = unrolled.size();
            int rot = k % L; 
            for (int j = left; j <= right; ++j) {
                grid[top][j] = unrolled[rot];
                rot = (rot + 1) % L;
            }
            for (int i = top + 1; i <= bottom; ++i) {
                grid[i][right] = unrolled[rot];
                rot = (rot + 1) % L;
            }
            for (int j = right - 1; j >= left; --j) {
                grid[bottom][j] = unrolled[rot];
                rot = (rot + 1) % L;
            }
            for (int i = bottom - 1; i > top; --i) {
                grid[i][left] = unrolled[rot];
                rot = (rot + 1) % L;
            }
        }
        
        return grid;
    }
};