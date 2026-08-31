#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;
    
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
      
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> dist(n + 1, 2e9 + 7);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[n] = 0;
        pq.push({0, n}); // {distance, node}

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue; // Skip stale entries

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        vector<int> memo(n + 1, -1);
        return dfs(1, n, adj, dist, memo);
    }

private:
    int dfs(int u, int target, vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& memo) {
        if (u == target) return 1;
        if (memo[u] != -1) return memo[u];

        long long count = 0;
        for (auto& edge : adj[u]) {
            int v = edge.first;
            if (dist[u] > dist[v]) {
                count = (count + dfs(v, target, adj, dist, memo)) % MOD;
            }
        }

        return memo[u] = count;
    }
};