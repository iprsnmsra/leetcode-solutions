#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (mat.empty() || mat[0].empty()) return {};

        int m = mat.size();
        int n = mat[0].size();
        vector<int> result(m * n);
        int idx = 0;
        for (int d = 0; d < m + n - 1; ++d) {
            
            if (d % 2 == 0) {

                int r = (d < m) ? d : m - 1;
                int c = d - r;
                
                while (r >= 0 && c < n) {
                    result[idx++] = mat[r][c];
                    r--; 
                    c++; 
                }
            } else {

                int c = (d < n) ? d : n - 1;
                int r = d - c;
                
                while (c >= 0 && r < m) {
                    result[idx++] = mat[r][c];
                    r++; 
                    c--; 
                }
            }
        }

        return result;
    }
};