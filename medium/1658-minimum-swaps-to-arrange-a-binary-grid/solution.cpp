#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = grid.size();
        vector<int> trailing_zeros(n, 0);
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) {
                    count++;
                } else {
                    break;
                }
            }
            trailing_zeros[i] = count;
        }

        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            int target = n - 1 - i;
            int j = i;
            while (j < n && trailing_zeros[j] < target) {
                j++;
            }
            if (j == n) {
                return -1;
            }
            int val = trailing_zeros[j];
            while (j > i) {
                trailing_zeros[j] = trailing_zeros[j - 1];
                swaps++;
                j--;
            }
            trailing_zeros[i] = val;
        }

        return swaps;
    }
};