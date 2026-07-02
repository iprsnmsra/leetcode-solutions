class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> min_damage(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;
        int start_damage = grid[0][0];
        min_damage[0][0] = start_damage;
        dq.push_back({0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            if (r == m - 1 && c == n - 1) {
                return (health - min_damage[r][c] >= 1);
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_damage = min_damage[r][c] + grid[nr][nc];
                    if (next_damage < min_damage[nr][nc]) {
                        min_damage[nr][nc] = next_damage;
                        if (grid[nr][nc] == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }

        return false;
    }
};