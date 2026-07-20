#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> parent;

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]); 
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();

        parent.resize(m * n);
        for (int i = 0; i < m * n; ++i) {
            parent[i] = i;
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {

                int curr = r * n + c; 

                if (c > 0 && grid[r][c] == grid[r][c - 1]) {
                    int left = r * n + (c - 1);
                    
                    int root_curr = find(curr);
                    int root_left = find(left);

                    if (root_curr == root_left) return true;

                    parent[root_curr] = root_left;
                }

                if (r > 0 && grid[r][c] == grid[r - 1][c]) {
                    int up = (r - 1) * n + c;

                    int root_curr = find(curr); 
                    int root_up = find(up);

                    if (root_curr == root_up) return true;

                    parent[root_curr] = root_up;
                }
            }
        }

        return false;
    }
};