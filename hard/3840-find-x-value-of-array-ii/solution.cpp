#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int K;

    // 1. Data Abstraction: 120-Byte Associative State Monoid
    struct Node {
        int trans[5];
        int cnt[5][5];

        Node() {
            for (int i = 0; i < 5; ++i) {
                trans[i] = 0;
                for (int j = 0; j < 5; ++j) {
                    cnt[i][j] = 0;
                }
            }
        }
    };

    vector<Node> tree;

    void init_leaf(int node, int val) {
        val %= K;
        for (int i = 0; i < K; ++i) {
            int nxt = (i * val) % K;
            tree[node].trans[i] = nxt;
            for (int j = 0; j < K; ++j) {
                tree[node].cnt[i][j] = (nxt == j ? 1 : 0);
            }
        }
    }

    // 2. The O(K^2) Monoid Merge
    Node merge(const Node& a, const Node& b) {
        Node res;
        for (int i = 0; i < K; ++i) {
            int mid_val = a.trans[i];
            res.trans[i] = b.trans[mid_val];
            for (int j = 0; j < K; ++j) {
                res.cnt[i][j] = a.cnt[i][j] + b.cnt[mid_val][j];
            }
        }
        return res;
    }

    void build(int node, int l, int r, const vector<int>& nums) {
        if (l == r) {
            init_leaf(node, nums[l]);
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, nums);
        build(2 * node + 1, mid + 1, r, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            init_leaf(node, val);
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx, val);
        else update(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];
        int mid = l + (r - l) / 2;
        if (qr <= mid) return query(2 * node, l, mid, ql, qr);
        if (ql > mid) return query(2 * node + 1, mid + 1, r, ql, qr);
        return merge(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        K = k;
        int n = nums.size();
        
        // Use 'assign' instead of 'resize' to guarantee absolutely pure memory on every execution
        tree.assign(4 * n, Node());
        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        // 3. The Logarithmic Execution Pipeline
        for (const auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            
            update(1, 0, n - 1, index, value);
            
            Node res = query(1, 0, n - 1, start, n - 1);
            
            // THE FIX: The mathematical multiplicative identity must be projected modulo K.
            // When K = 1, (1 % 1) safely targets the 0-state row, bypassing the Out-Of-Bounds trap.
            ans.push_back(res.cnt[1 % K][x]);
        }

        return ans;
    }
};