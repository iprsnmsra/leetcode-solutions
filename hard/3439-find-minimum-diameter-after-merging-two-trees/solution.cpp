#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int d1 = getDiameter(edges1);
        int d2 = getDiameter(edges2);

        int r1 = (d1 + 1) / 2;
        int r2 = (d2 + 1) / 2;

        return max({d1, d2, r1 + r2 + 1});
    }

private:
    int getDiameter(const vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        if (n <= 1) return 0;

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        auto [furthest_node, _] = bfs(0, n, adj);

        auto [_, diameter] = bfs(furthest_node, n, adj);

        return diameter;
    }

    pair<int, int> bfs(int start, int n, const vector<vector<int>>& adj) {
        vector<int> dist(n, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        int furthest_node = start;
        int max_dist = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (dist[curr] > max_dist) {
                max_dist = dist[curr];
                furthest_node = curr;
            }

            for (int neighbor : adj[curr]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[curr] + 1;
                    q.push(neighbor);
                }
            }
        }

        return {furthest_node, max_dist};
    }
};