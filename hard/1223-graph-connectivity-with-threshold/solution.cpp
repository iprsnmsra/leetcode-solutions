#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

// Standard Disjoint Set Union (Union-Find) with Path Compression and Union by Rank
class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        // Initially, every node is its own parent (roots of their own trees)
        iota(parent.begin(), parent.end(), 0); 
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        // Path compression: point directly to the absolute root for O(1) future lookups
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank: attach the smaller tree under the taller tree
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        DSU dsu(n + 1); 
        for (int z = threshold + 1; z <= n; ++z) {
            for (int m = z * 2; m <= n; m += z) {
                dsu.unite(z, m);
            }
        }
        vector<bool> answer;
        answer.reserve(queries.size());
        
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            answer.push_back(dsu.find(u) == dsu.find(v));
        }

        return answer;
    }
};