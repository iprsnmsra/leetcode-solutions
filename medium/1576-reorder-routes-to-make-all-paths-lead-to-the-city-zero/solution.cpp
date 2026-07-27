#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<pair<int, int>>> adj(n);

        for (const auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            
            adj[u].push_back({v, 1});

            adj[v].push_back({u, 0});
        }

        return dfs(0, -1, adj);
    }

private:
    int dfs(int node, int parent, const vector<vector<pair<int, int>>>& adj) {
        int total_flips = 0;

        for (const auto& edge : adj[node]) {
            int neighbor = edge.first;
            int flip_cost = edge.second;

            if (neighbor != parent) {
                total_flips += flip_cost + dfs(neighbor, node, adj);
            }
        }

        return total_flips;
    }
};