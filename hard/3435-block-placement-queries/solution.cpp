#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class SegmentTree {
    int n;
    vector<int> tree;
public:
    SegmentTree(int n) : n(n), tree(4 * n, 0) {}

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return 0;
        if (L <= start && end <= R) return tree[node];
        
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, L, R),
                   query(2 * node + 1, mid + 1, end, L, R));
    }

    int query(int L, int R) {
        if (L > R) return 0; // Invalid range safeguard
        return query(1, 0, n - 1, L, R);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        SegmentTree st(max_x + 1);
        set<int> obs;
        obs.insert(0); 
        
        vector<bool> ans;
        
        for (const auto& q : queries) {
            if (q[0] == 1) { 
                int x = q[1];

                auto it = obs.upper_bound(x);
                int prev = *std::prev(it);
                
                if (it != obs.end()) {
                    int nxt = *it;
                    st.update(nxt, nxt - x); 
                }

                st.update(x, x - prev);
                obs.insert(x);
                
            } else {
                int x = q[1];
                int sz = q[2];

                auto it = obs.upper_bound(x);
                int prev = *std::prev(it);

                int max_gap = st.query(0, prev);

                max_gap = max(max_gap, x - prev);

                ans.push_back(max_gap >= sz);
            }
        }
        
        return ans;
    }
};