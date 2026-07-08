#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // The function name is now exactly 'minCost' to match LeetCode's backend
    int minCost(int n, vector<vector<int>>& edges) {
        // 1. Build the adjacency list with Virtual Edges included
        // pair<node, cost>
        vector<vector<pair<int, int>>> adj(n);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            // Standard forward edge
            adj[u].push_back({v, w});
            
            // Virtual reversed edge with double the cost
            adj[v].push_back({u, 2 * w});
        }
        
        // 2. Standard Dijkstra's Algorithm setup
        vector<int> dist(n, 1e9); // 1e9 acts as infinity
        
        // Min-heap stores {current_cost, current_node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[0] = 0;
        pq.push({0, 0});
        
        // 3. Execute Dijkstra
        while (!pq.empty()) {
            auto [current_cost, u] = pq.top();
            pq.pop();
            
            // Optimization: If we found a faster way to 'u' previously, discard this outdated path
            if (current_cost > dist[u]) continue;
            
            // Early exit if we reached the destination
            if (u == n - 1) return current_cost;
            
            // Explore all neighbors (both original and virtual)
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                // Relaxation step
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Destination is unreachable
        return -1;
    }
};