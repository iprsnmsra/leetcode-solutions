#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        int max_idle_time = 0;
        for (int i = 1; i < n; ++i) {
            int round_trip = 2 * dist[i];
            int p = patience[i];

            int last_resend_time = ((round_trip - 1) / p) * p;
            int last_message_arrival = last_resend_time + round_trip;
            
            max_idle_time = max(max_idle_time, last_message_arrival);
        }
        return max_idle_time + 1;
    }
};