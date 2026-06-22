#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
class SparseTableRMQ {
    int n;
    int max_log;
    vector<vector<int>> f_max;
    vector<vector<int>> f_min;
    vector<int> lg;

public:
    SparseTableRMQ(const vector<int>& data) {
        n = data.size();
        max_log = 32 - __builtin_clz(n);
        
        f_max.assign(n, vector<int>(max_log, 0));
        f_min.assign(n, vector<int>(max_log, 0));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i >> 1] + 1;
        }

        for (int i = 0; i < n; i++) {
            f_max[i][0] = data[i];
            f_min[i][0] = data[i];
        }

        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i <= n - (1 << j); i++) {
                f_max[i][j] = max(f_max[i][j - 1], f_max[i + (1 << (j - 1))][j - 1]);
                f_min[i][j] = min(f_min[i][j - 1], f_min[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query_max(int l, int r) {
        int k = lg[r - l + 1];
        return max(f_max[l][k], f_max[r - (1 << k) + 1][k]);
    }

    int query_min(int l, int r) {
        int k = lg[r - l + 1];
        return min(f_min[l][k], f_min[r - (1 << k) + 1][k]);
    }
};
struct SubarrayState {
    long long val;
    int l;
    int r;
    bool operator<(const SubarrayState& other) const {
        return val < other.val;
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        SparseTableRMQ st(nums);
        priority_queue<SubarrayState> pq;
        for (int l = 0; l < n; l++) {
            long long val = (long long)st.query_max(l, n - 1) - st.query_min(l, n - 1);
            pq.push({val, l, n - 1});
        }

        long long total_value = 0;
        for (int i = 0; i < k; i++) {
            auto [val, l, r] = pq.top();
            pq.pop();

            total_value += val;
            if (r > l) {
                long long next_val = (long long)st.query_max(l, r - 1) - st.query_min(l, r - 1);
                pq.push({next_val, l, r - 1});
            }
        }

        return total_value;
    }
};