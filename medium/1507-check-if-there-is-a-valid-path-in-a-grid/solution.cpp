#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int, vector<pair<int, int>>> ports = {
            {1, {{0, -1}, {0, 1}}},  
            {2, {{-1, 0}, {1, 0}}},  
            {3, {{0, -1}, {1, 0}}}, 
            {4, {{0, 1}, {1, 0}}}, 
            {5, {{0, -1}, {-1, 0}}}, 
            {6, {{0, 1}, {-1, 0}}}   
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) return true;
            for (auto& dir : ports[grid[r][c]]) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {

                    bool handshake = false;
                    pair<int, int> back_dir = {-dir.first, -dir.second};
                    
                    for (auto& neighbor_port : ports[grid[nr][nc]]) {
                        if (neighbor_port == back_dir) {
                            handshake = true;
                            break;
                        }
                    }

                    if (handshake) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return false;
    }
};