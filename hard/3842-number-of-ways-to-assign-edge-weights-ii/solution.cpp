#include <vector>
#include <iostream>

using namespace std;

class Solution {
    int MOD = 1e9 + 7;
    int LOG = 20;
    
    vector<vector<int>> up;
    vector<int> depth;
    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    void dfs(int node, int parent, const vector<vector<int>>& adj) {
        up[node][0] = parent;
        for (int i = 1; i < LOG; i++) {
            up[node][i] = up[ up[node][i-1] ][i-1];
        }
        
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                depth[neighbor] = depth[node] + 1;
                dfs(neighbor, node, adj);
            }
        }
    }
    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        up.assign(n + 1, vector<int>(LOG, 1));
        depth.assign(n + 1, 0);
        dfs(1, 1, adj);
        
        vector<int> answer;
        answer.reserve(queries.size());
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                answer.push_back(0);
                continue;
            }
            
            int lca = getLCA(u, v);
            int d = depth[u] + depth[v] - 2 * depth[lca];
            answer.push_back(modPow(2, d - 1));
        }
        
        return answer;
    }
};