#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;

        vector<vector<int>> p(n, vector<int>(m));

        long long pref = 1;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                p[r][c] = pref; 
                pref = (pref * grid[r][c]) % MOD; 
            }
        }
        long long suff = 1;
        for (int r = n - 1; r >= 0; --r) {
            for (int c = m - 1; c >= 0; --c) {
                p[r][c] = (p[r][c] * suff) % MOD; 
                suff = (suff * grid[r][c]) % MOD; 
            }
        }

        return p;
    }
};