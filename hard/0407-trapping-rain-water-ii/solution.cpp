
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = heightMap.size();
        if (m <= 2) return 0;
        int n = heightMap[0].size();
        if (n <= 2) return 0;
        priority_queue<uint32_t, vector<uint32_t>, greater<uint32_t>> pq;
        vector<bool> visited(m * n, false);
        for (int i = 0; i < m; ++i) {
            pq.push((heightMap[i][0] << 16) | (i << 8) | 0);
            visited[i * n] = true;
            
            pq.push((heightMap[i][n - 1] << 16) | (i << 8) | (n - 1));
            visited[i * n + n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            pq.push((heightMap[0][j] << 16) | (0 << 8) | j);
            visited[j] = true;
            
            pq.push((heightMap[m - 1][j] << 16) | ((m - 1) << 8) | j);
            visited[(m - 1) * n + j] = true;
        }

        int water = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty()) {
            uint32_t cell = pq.top();
            pq.pop();
            int h = cell >> 16;
            int r = (cell >> 8) & 0xFF;
            int c = cell & 0xFF;
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr * n + nc]) {
                    visited[nr * n + nc] = true;
                    int nh = heightMap[nr][nc];
                    
                    if (nh < h) {
                        water += h - nh;
                    }
                    int new_boundary_height = max(nh, h);
                    pq.push((new_boundary_height << 16) | (nr << 8) | nc);
                }
            }
        }

        return water;
    }
};