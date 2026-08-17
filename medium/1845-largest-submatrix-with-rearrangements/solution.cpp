#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = matrix.size();
        int n = matrix[0].size();
        int max_area = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c] != 0 && r > 0) {
                    matrix[r][c] += matrix[r - 1][c];
                }
            }
            vector<int> current_heights = matrix[r];
            sort(current_heights.begin(), current_heights.end(), greater<int>());
            for (int c = 0; c < n; ++c) {
                if (current_heights[c] == 0) {
                    break; 
                }
                int current_area = current_heights[c] * (c + 1);
                max_area = max(max_area, current_area);
            }
        }

        return max_area;
    }
};