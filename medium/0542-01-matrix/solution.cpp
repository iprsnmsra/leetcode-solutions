class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = mat.size();
        int n = mat[0].size();
        int INF = 1e9; 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) continue;
                
                mat[i][j] = INF; 
                
                if (i > 0) mat[i][j] = min(mat[i][j], mat[i - 1][j] + 1);
                if (j > 0) mat[i][j] = min(mat[i][j], mat[i][j - 1] + 1);
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (mat[i][j] == 0) continue;
                
                if (i < m - 1) mat[i][j] = min(mat[i][j], mat[i + 1][j] + 1);
                if (j < n - 1) mat[i][j] = min(mat[i][j], mat[i][j + 1] + 1);
            }
        }

        return mat;
    }
};