#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    long long MOD = 1e9 + 7;
    
    // Flat L1/L2 Cache Arrays for Segment Tree (Zero Object Overhead)
    vector<long long> sum;
    vector<long long> sq;
    vector<long long> lazy;

    // The Mathematical Engine: Polynomial Expansion
    void apply(int node, int L, int R, long long val) {
        long long len = R - L + 1;
        long long val_sq = (val * val) % MOD;
        
        // (S + v)^2 = S^2 + 2*v*S + v^2*L
        sq[node] = (sq[node] + 2 * val * sum[node] + val_sq * len) % MOD;
        // (S + v) = S + v*L
        sum[node] = (sum[node] + val * len) % MOD;
        // Accumulate pending lazy operations
        lazy[node] = (lazy[node] + val) % MOD;
    }

    // Lazy Propagation: Push state down to children before querying or modifying them
    void push_down(int node, int L, int R) {
        if (lazy[node] != 0 && L != R) {
            int mid = L + (R - L) / 2;
            apply(2 * node, L, mid, lazy[node]);
            apply(2 * node + 1, mid + 1, R, lazy[node]);
            lazy[node] = 0; // State successfully flushed
        }
    }

    // State Consolidation: Pull updated state up from children
    void push_up(int node) {
        sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
        sq[node] = (sq[2 * node] + sq[2 * node + 1]) % MOD;
    }

    // Logarithmic Range Update Traversal
    void update(int node, int L, int R, int qL, int qR, long long val) {
        if (qL > R || qR < L) return; // Out of bounds
        
        // Complete segment overlap: Apply algebra instantly and halt recursion
        if (qL <= L && R <= qR) {
            apply(node, L, R, val);
            return;
        }
        
        push_down(node, L, R);
        int mid = L + (R - L) / 2;
        update(2 * node, L, mid, qL, qR, val);
        update(2 * node + 1, mid + 1, R, qL, qR, val);
        push_up(node);
    }

public:
    int sumCounts(vector<int>& nums) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        // Value space is bounded by 10^5, allowing a flat array over a hash map
        vector<int> last_seen(100005, -1);
        long long total_ans = 0;

        // The Forward Sweep
        for (int i = 0; i < n; ++i) {
            int prev = last_seen[nums[i]];
            
            // Add 1 to distinct counts for all subarrays starting between (prev, i]
            update(1, 0, n - 1, prev + 1, i, 1);
            
            // The root node guarantees O(1) extraction of the total sum of squares for this iteration
            total_ans = (total_ans + sq[1]) % MOD;
            
            last_seen[nums[i]] = i;
        }

        return total_ans;
    }
};