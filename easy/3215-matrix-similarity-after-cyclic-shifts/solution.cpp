#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = mat.size();
        int n = mat[0].size();

        k = k % n;
        if (k == 0) return true;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] != mat[r][(c + k) % n]) {
                    return false;
                }
            }
        }

        return true;
    }
};