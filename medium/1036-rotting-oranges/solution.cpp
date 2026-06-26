#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int, int>> q;
        int fresh_count = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c}); 
                } else if (grid[r][c] == 1) {
                    fresh_count++;
                }
            }
        }
        if (fresh_count == 0) return 0;
        
        int minutes = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty() && fresh_count > 0) {
            int level_size = q.size();
            
            for (int i = 0; i < level_size; ++i) {
                auto curr = q.front();
                q.pop();
                
                int r = curr.first;
                int c = curr.second;
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh_count--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        return fresh_count == 0 ? minutes : -1;
    }
};