#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> left(cols, 0);
        vector<int> right(cols, cols);
        vector<int> height(cols, 0);

        int maxArea = 0;

        for (const auto& row : matrix) {
            int cur_left = 0, cur_right = cols;

            // 1. Update Heights
            for (int j = 0; j < cols; j++) {
                if (row[j] == '1') height[j]++;
                else height[j] = 0;
            }

            // 2. Update Left Boundaries
            for (int j = 0; j < cols; j++) {
                if (row[j] == '1') {
   
                    left[j] = max(left[j], cur_left);
                } else {

                    left[j] = 0;
                    cur_left = j + 1; // The next possible start is j+1
                }
            }

            // 3. Update Right Boundaries

            for (int j = cols - 1; j >= 0; j--) {
                if (row[j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = cols;
                    cur_right = j; // The next possible end is j
                }
            }

            // 4. Calculate Area for this row
            for (int j = 0; j < cols; j++) {
          
                int area = (right[j] - left[j]) * height[j];
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};