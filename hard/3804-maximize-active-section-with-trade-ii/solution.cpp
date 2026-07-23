#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// --- Range Maximum Query Sparse Table ---
class SparseTableMax {
    vector<vector<int>> st;
public:
    SparseTableMax(const vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return;
        int log_n = 32 - __builtin_clz(n);
        st.assign(log_n, vector<int>(n));
        for (int i = 0; i < n; i++) st[0][i] = arr[i];
        for (int j = 1; j < log_n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    int query(int L, int R) {
        if (L > R) return 0; 
        int j = 31 - __builtin_clz(R - L + 1);
        return max(st[j][L], st[j][R - (1 << j) + 1]);
    }
};

class SparseTableMin {
    vector<vector<int>> st;
public:
    SparseTableMin(const vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return;
        int log_n = 32 - __builtin_clz(n);
        st.assign(log_n, vector<int>(n));
        for (int i = 0; i < n; i++) st[0][i] = arr[i];
        for (int j = 1; j < log_n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    int query(int L, int R) {
        if (L > R) return 1e9;
        int j = 31 - __builtin_clz(R - L + 1);
        return min(st[j][L], st[j][R - (1 << j) + 1]);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        int global_ones = 0;
        for (char c : s) if (c == '1') global_ones++;
        vector<pair<int, int>> Z_blocks;
        int start = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (start == -1) start = i;
            } else {
                if (start != -1) {
                    Z_blocks.push_back({start, i - 1});
                    start = -1;
                }
            }
        }
        if (start != -1) Z_blocks.push_back({start, n - 1});

        int K = Z_blocks.size();
        vector<int> Z(K), L(K > 0 ? K - 1 : 0), Pairs(K > 0 ? K - 1 : 0);
        
        for (int i = 0; i < K; ++i) {
            Z[i] = Z_blocks[i].second - Z_blocks[i].first + 1;
        }
        for (int i = 0; i < K - 1; ++i) {
            L[i] = Z_blocks[i + 1].first - Z_blocks[i].second - 1;
            Pairs[i] = Z[i] + Z[i + 1];
        }

        SparseTableMax st_Z(Z);
        SparseTableMin st_L(L);
        SparseTableMax st_Pairs(Pairs);
        vector<int> next_zero(n, -1), prev_zero(n, -1), block_id(n, -1);
        int last_z = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') last_z = i;
            prev_zero[i] = last_z;
        }
        int nxt_z = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') nxt_z = i;
            next_zero[i] = nxt_z;
        }
        for (int i = 0; i < K; ++i) {
            for (int j = Z_blocks[i].first; j <= Z_blocks[i].second; ++j) {
                block_id[j] = i;
            }
        }
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int qL = q[0], qR = q[1];
            int f0 = next_zero[qL];
            int l0 = prev_zero[qR];
            if (f0 == -1 || f0 > qR || block_id[f0] == block_id[l0]) {
                ans.push_back(global_ones);
                continue;
            }

            int bid_a = block_id[f0];
            int bid_b = block_id[l0];
            int z_a = min(qR, Z_blocks[bid_a].second) - f0 + 1;
            int z_b = l0 - max(qL, Z_blocks[bid_b].first) + 1;
            int max_z = max(z_a, z_b);
            if (bid_a + 1 <= bid_b - 1) {
                max_z = max(max_z, st_Z.query(bid_a + 1, bid_b - 1));
            }

            int min_l = st_L.query(bid_a, bid_b - 1);

            int max_pair = 0;
            if (bid_a + 1 == bid_b) {
                max_pair = z_a + z_b;
            } else {
                max_pair = max(z_a + Z[bid_a + 1], Z[bid_b - 1] + z_b);
                if (bid_a + 1 <= bid_b - 2) {
                    max_pair = max(max_pair, st_Pairs.query(bid_a + 1, bid_b - 2));
                }
            }
            int gain = max(max_pair, max_z - min_l);
            ans.push_back(global_ones + gain);
        }

        return ans;
    }
};