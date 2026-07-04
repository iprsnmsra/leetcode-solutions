#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = online.size();

        struct Edge {
            int to;
            long long cost;
        };

        vector<vector<Edge>> adj(n);
        vector<int> indegree(n, 0);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            long long cost = edge[2];
            if (online[u] && online[v]) {
                adj[u].push_back({v, cost});
                indegree[v]++;
            }
        }
        vector<int> topo;
        topo.reserve(n);
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (const auto& edge : adj[u]) {
                if (--indegree[edge.to] == 0) {
                    q.push(edge.to);
                }
            }
        }
        long long low = 0;
        long long high = 1e9;
        long long best_score = -1;
        const long long INF = 1e16; 

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            vector<long long> dist(n, INF);
            dist[0] = 0;
            for (int u : topo) {
                if (dist[u] == INF) continue;

                for (const auto& edge : adj[u]) {
                    if (edge.cost >= mid) {
                        dist[edge.to] = min(dist[edge.to], dist[u] + edge.cost);
                    }
                }
            }
            if (dist[n - 1] <= k) {
                best_score = mid; 
                low = mid + 1;   
            } else {
                high = mid - 1;   
            }
        }

        return best_score;
    }
};