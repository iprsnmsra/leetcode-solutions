#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int valid_sets = 0;
        int total_masks = 1 << n; 
        const int INF = 1e9;      

        for (int mask = 0; mask < total_masks; ++mask) {

            vector<vector<int>> dist(n, vector<int>(n, INF));
            for (int i = 0; i < n; ++i) {
                dist[i][i] = 0;
            }

            for (const auto& road : roads) {
                int u = road[0];
                int v = road[1];
                int w = road[2];

                if (((mask >> u) & 1) && ((mask >> v) & 1)) {

                    dist[u][v] = min(dist[u][v], w);
                    dist[v][u] = min(dist[v][u], w);
                }
            }

            for (int k = 0; k < n; ++k) {
                if (!((mask >> k) & 1)) continue; 
                
                for (int i = 0; i < n; ++i) {
                    if (!((mask >> i) & 1)) continue; 
                    
                    for (int j = 0; j < n; ++j) {
                        if (!((mask >> j) & 1)) continue; 
                        
                        if (dist[i][k] != INF && dist[k][j] != INF) {
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }

            bool is_valid = true;
            for (int i = 0; i < n; ++i) {
                if (!((mask >> i) & 1)) continue;
                for (int j = i + 1; j < n; ++j) {
                    if (!((mask >> j) & 1)) continue;
                    
                    if (dist[i][j] > maxDistance) {
                        is_valid = false;
                        break;
                    }
                }
                if (!is_valid) break;
            }

            if (is_valid) {
                valid_sets++;
            }
        }

        return valid_sets;
    }
};