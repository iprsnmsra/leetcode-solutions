#include <vector>
#include <deque>
#include <tuple>

using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<int>> cost(m, vector<int>(n, 1e9));
        cost[0][0] = 0;

        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            if (r == m - 1 && c == n - 1) {
                return cost[r][c];
            }
            
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc];

                    if (cost[r][c] + weight < cost[nr][nc]) {
                        cost[nr][nc] = cost[r][c] + weight;

                        if (weight == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc}); 
                        }
                    }
                }
            }
        }
        
        return 0; 
    }
};