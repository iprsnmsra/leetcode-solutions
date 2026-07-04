class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }
        int min_score = 1e9; 
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (const auto& edge : adj[curr]) {
                int next_city = edge.first;
                int road_dist = edge.second;
                if (road_dist < min_score) {
                    min_score = road_dist;
                }
                if (!visited[next_city]) {
                    visited[next_city] = true;
                    q.push(next_city);
                }
            }
        }

        return min_score;
    }
};