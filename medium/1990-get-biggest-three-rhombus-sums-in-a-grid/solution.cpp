#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    inline void updateTop3(int val, int& m1, int& m2, int& m3) {
        if (val == m1 || val == m2 || val == m3) return; 
        
        if (val > m1) {
            m3 = m2;
            m2 = m1;
            m1 = val;
        } else if (val > m2) {
            m3 = m2;
            m2 = val;
        } else if (val > m3) {
            m3 = val;
        }
    }

public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        int m1 = -1, m2 = -1, m3 = -1;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                updateTop3(grid[r][c], m1, m2, m3);
                for (int L = 1; r + 2 * L < m && c - L >= 0 && c + L < n; ++L) {
                    int current_sum = 0;
                    current_sum += grid[r][c];                
                    current_sum += grid[r + 2 * L][c];       
                    current_sum += grid[r + L][c - L];        
                    current_sum += grid[r + L][c + L];        
                    for (int k = 1; k < L; ++k) {
                        current_sum += grid[r + k][c + k];           
                        current_sum += grid[r + L + k][c + L - k];  
                        current_sum += grid[r + 2 * L - k][c - k];   
                        current_sum += grid[r + L - k][c - L + k];     
                    }
                    updateTop3(current_sum, m1, m2, m3);
                }
            }
        }
        vector<int> result;
        if (m1 != -1) result.push_back(m1);
        if (m2 != -1) result.push_back(m2);
        if (m3 != -1) result.push_back(m3);
        
        return result;
    }
};