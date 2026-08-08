#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = grid.size();
        int pairs = 0;
        map<vector<int>, int> row_counts;
        
        for (int r = 0; r < n; ++r) {
            row_counts[grid[r]]++;
        }
        for (int c = 0; c < n; ++c) {
            vector<int> col(n);
            for (int r = 0; r < n; ++r) {
                col[r] = grid[r][c];
            }
            pairs += row_counts[col];
        }

        return pairs;
    }
};