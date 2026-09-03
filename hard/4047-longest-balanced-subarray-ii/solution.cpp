#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class SegmentTree {
    int n;
    vector<int> min_val;
    vector<int> max_val;
    vector<int> lazy;
    const int INF = 1e9;

public:
    SegmentTree(int n) : n(n) {
        min_val.assign(4 * n, INF);
        max_val.assign(4 * n, -INF);
        lazy.assign(4 * n, 0);
    }

    void push(int v) {
        if (lazy[v] != 0) {
            lazy[2 * v] += lazy[v];
            min_val[2 * v] += lazy[v];
            max_val[2 * v] += lazy[v];

            lazy[2 * v + 1] += lazy[v];
            min_val[2 * v + 1] += lazy[v];
            max_val[2 * v + 1] += lazy[v];

            lazy[v] = 0;
        }
    }

    // Set a specific leaf node to a value (used to activate index R)
    void set(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            min_val[v] = val;
            max_val[v] = val;
            lazy[v] = 0;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            if (pos <= tm) set(2 * v, tl, tm, pos, val);
            else set(2 * v + 1, tm + 1, tr, pos, val);
            
            min_val[v] = min(min_val[2 * v], min_val[2 * v + 1]);
            max_val[v] = max(max_val[2 * v], max_val[2 * v + 1]);
        }
    }

    // Add 'val' to all indices in range [l, r]
    void update(int v, int tl, int tr, int l, int r, int add) {
        if (l > r) return;
        if (l == tl && r == tr) {
            min_val[v] += add;
            max_val[v] += add;
            lazy[v] += add;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), add);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
            
            min_val[v] = min(min_val[2 * v], min_val[2 * v + 1]);
            max_val[v] = max(max_val[2 * v], max_val[2 * v + 1]);
        }
    }

    // Find the leftmost index where value is 0
    int find_first_zero(int v, int tl, int tr) {
        // Pruning: If 0 is not in the [min, max] range, it doesn't exist here
        if (min_val[v] > 0 || max_val[v] < 0) return -1;
        
        if (tl == tr) return tl;
        
        push(v);
        int tm = (tl + tr) / 2;
        
        // Try left child first (to find leftmost)
        int res = find_first_zero(2 * v, tl, tm);
        if (res != -1) return res;
        
        // If not in left, try right
        return find_first_zero(2 * v + 1, tm + 1, tr);
    }

    void set_index(int pos, int val) {
        set(1, 0, n - 1, pos, val);
    }

    void add_range(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    int query_zero() {
        return find_first_zero(1, 0, n - 1);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        SegmentTree st(n);
        
        vector<int> last_pos(100001, -1);
        
        int max_len = 0;

        for (int r = 0; r < n; ++r) {
            int val = nums[r];
            int prev = last_pos[val];
            
       
            st.set_index(r, 0);
            
            int delta = (val % 2 == 0) ? 1 : -1;
            st.add_range(prev + 1, r, delta);
            
            // 3. Update history
            last_pos[val] = r;
            
            // 4. Find the leftmost 'L' such that balance is 0
            int l = st.query_zero();
            if (l != -1) {
                max_len = max(max_len, r - l + 1);
            }
        }

        return max_len;
    }
};