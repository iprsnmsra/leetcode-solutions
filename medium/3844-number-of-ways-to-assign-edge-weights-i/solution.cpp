#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
    long long modularExponentiation(long long base, long long exp) {
        long long res = 1;
        long long mod = 1e9 + 7;
        base %= mod;
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int max_depth = 0;
        queue<pair<int, int>> q; 
        vector<bool> visited(n + 1, false);

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, depth] = q.front();
            q.pop();
            if (depth > max_depth) {
                max_depth = depth;
            }

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, depth + 1});
                }
            }
        }
        if (max_depth == 0) return 0;
        return modularExponentiation(2, max_depth - 1);
    }
};