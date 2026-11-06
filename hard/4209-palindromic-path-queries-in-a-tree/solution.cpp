#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> tin, tout, bit;
    vector<vector<int>> up;
    int timer;
    int max_time;

    // L1 Cache Contiguous Forward Star Graph
    vector<int> head, to, nxt;
    int edge_cnt;

    void add_edge(int u, int v) {
        to[edge_cnt] = v;
        nxt[edge_cnt] = head[u];
        head[u] = edge_cnt++;
    }

    // Point Update on the Fenwick Tree
    void update_bit(int idx, int val) {
        for (; idx <= max_time; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    // Prefix XOR Query on the Fenwick Tree
    int query_bit(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= bit[idx];
        }
        return res;
    }

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;
        
        // Populate Binary Lifting table
        for (int i = 1; i < 16; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        
        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            if (v != p) dfs(v, u);
        }
        
        tout[u] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int get_lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        
        for (int i = 15; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        // Fast I/O execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Zero-allocation initialization
        tin.assign(n, 0);
        tout.assign(n, 0);
        up.assign(n, vector<int>(16, 0));
        max_time = 2 * n + 1;
        bit.assign(max_time + 1, 0);
        timer = 0;
        edge_cnt = 0;

        head.assign(n, -1);
        to.resize(2 * n);
        nxt.resize(2 * n);

        for (const auto& e : edges) {
            add_edge(e[0], e[1]);
            add_edge(e[1], e[0]);
        }

        // 1. Flatten the tree topology
        dfs(0, 0);

        // 2. Populate the Fenwick Tree based on initial string
        for (int i = 0; i < n; ++i) {
            int val = 1 << (s[i] - 'a');
            update_bit(tin[i], val);
            update_bit(tout[i], val);
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        // 3. Process Queries using strict manual parsing to bypass stringstream overhead
        for (const string& q : queries) {
            if (q[0] == 'u') {
                int u = 0, ptr = 7;
                while (q[ptr] != ' ') {
                    u = u * 10 + (q[ptr++] - '0');
                }
                char new_char = q[ptr + 1];
                
                int old_val = 1 << (s[u] - 'a');
                int new_val = 1 << (new_char - 'a');
                int delta = old_val ^ new_val;
                
                update_bit(tin[u], delta);
                update_bit(tout[u], delta);
                s[u] = new_char;
                
            } else {
                int u = 0, v = 0, ptr = 6;
                while (q[ptr] != ' ') {
                    u = u * 10 + (q[ptr++] - '0');
                }
                ptr++;
                while (ptr < q.length()) {
                    v = v * 10 + (q[ptr++] - '0');
                }
                
                int lca = get_lca(u, v);
                
                // Path Mask = Root->U ^ Root->V ^ LCA(U, V)
                int mask_u = query_bit(tin[u]);
                int mask_v = query_bit(tin[v]);
                int lca_char = 1 << (s[lca] - 'a');
                
                int path_mask = mask_u ^ mask_v ^ lca_char;
                
                // A valid palindrome mask has exactly 1 or 0 bits set
                ans.push_back((path_mask & (path_mask - 1)) == 0);
            }
        }

        return ans;
    }
};