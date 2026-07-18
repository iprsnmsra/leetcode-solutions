#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        int total_elements = m * n;

        vector<int> arr(total_elements);
        int idx = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                arr[idx++] = grid[r][c];
            }
        }

        int expected_remainder = arr[0] % x;
        for (int i = 1; i < total_elements; ++i) {
            if (arr[i] % x != expected_remainder) {
                return -1; 
            }
        }
        int mid_index = total_elements / 2;

        nth_element(arr.begin(), arr.begin() + mid_index, arr.end());
        int target_median = arr[mid_index];

        int total_ops = 0;
        for (int i = 0; i < total_elements; ++i) {
            total_ops += abs(arr[i] - target_median) / x;
        }

        return total_ops;
    }
};